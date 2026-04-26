cat > 100-elf_header.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
	* print_magic - prints ELF magic
	* @e_ident: identifier
	*/
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
}

/**
	* print_class - prints class
	* @e_ident: identifier
	*/
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else
		printf("<unknown>\n");
}

/**
	* print_data - prints data format
	* @e_ident: identifier
	*/
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown>\n");
}

/**
	* print_version - prints version
	* @e_ident: identifier
	*/
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d (current)\n",
	       e_ident[EI_VERSION]);
}

/**
	* print_osabi - prints OS/ABI
	* @e_ident: identifier
	*/
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		default:
			printf("<unknown>\n");
	}
}

/**
	* print_abi - prints ABI version
	* @e_ident: identifier
	*/
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
	* main - entry
	* @argc: arg count
	* @argv: args
	*
	* Return: 0
	*/
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(2, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(2, "Error: Can't read ELF header\n");
		close(fd);
		exit(98);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	    header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 ||
	    header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(2, "Error: Not an ELF file\n");
		close(fd);
		exit(98);
	}

	printf("ELF Header:\n");

	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_osabi(header.e_ident);
	print_abi(header.e_ident);

	printf("  Type:                              %x\n", header.e_type);
	printf("  Entry point address:               0x%lx\n",
	       header.e_entry);

	close(fd);
	return (0);
}
