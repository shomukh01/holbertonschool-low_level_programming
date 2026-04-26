#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

unsigned int get16(unsigned char *b, int big)
{
	if (big)
		return ((b[0] << 8) | b[1]);
	return (b[0] | (b[1] << 8));
}

unsigned long get32(unsigned char *b, int big)
{
	if (big)
		return ((unsigned long)b[0] << 24) | ((unsigned long)b[1] << 16) |
		       ((unsigned long)b[2] << 8) | b[3];
	return b[0] | ((unsigned long)b[1] << 8) |
	       ((unsigned long)b[2] << 16) | ((unsigned long)b[3] << 24);
}

void print_type(unsigned int type)
{
	printf("Type: ");
	if (type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (type == ET_REL)
		printf("REL (Relocatable file)\n");
	else
		printf("<unknown>\n");
}

int main(int argc, char **argv)
{
	int fd, i, big;
	unsigned char h[64];

	if (argc != 2)
		exit(98);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || read(fd, h, 64) != 64)
		exit(98);

	if (h[0] != 0x7f || h[1] != 'E' || h[2] != 'L' || h[3] != 'F')
		exit(98);

	big = (h[EI_DATA] == ELFDATA2MSB);

	printf("ELF Header:\n");
	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", h[i], i == EI_NIDENT - 1 ? "\n" : " ");
	printf("Class: %s\n", h[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("Data: %s\n", big ? "2's complement, big endian" :
	       "2's complement, little endian");
	printf("Version: %d (current)\n", h[EI_VERSION]);

	printf("OS/ABI: ");
	if (h[EI_OSABI] == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else if (h[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (h[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", h[EI_OSABI]);

	printf("ABI Version: %d\n", h[EI_ABIVERSION]);
	print_type(get16(h + 16, big));
	printf("Entry point address: 0x%lx\n", get32(h + 24, big));

	close(fd);
	return (0);
}
