#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * print_error - Prints the error message and exits with status 98.
 * @msg: The error message to print.
 */
void print_error(char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * print_elf_header - Prints the information contained in the ELF header.
 * @header: The ELF header structure.
 */
void print_elf_header(Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
	printf("  Class:                             ");
	printf(header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64\n" : "ELF32\n");
	printf("  Data:                              ");
	printf(header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian\n" :
	       "2's complement, big endian\n");
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
		case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
		case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
		case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
		case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
		case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
		case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
		case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
		case ELFOSABI_ARM: printf("UNIX - ARM architecture\n"); break;
		case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
		default: printf("<unknown: %x>\n", header->e_ident[EI_OSABI]); break;
	}
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (header->e_type)
	{
		case ET_NONE: printf("NONE (No file type)\n"); break;
		case ET_REL: printf("REL (Relocatable file)\n"); break;
		case ET_EXEC: printf("EXEC (Executable file)\n"); break;
		case ET_DYN: printf("DYN (Shared object file)\n"); break;
		case ET_CORE: printf("CORE (Core file)\n"); break;
		default: printf("<unknown: %x>\n", header->e_type); break;
	}
	printf("  Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or the corresponding error code on failure.
 */
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Cannot open file");

	if (read(fd, &header, sizeof(header)) != sizeof(header))
		print_error("Error: Cannot read file");

	if (lseek(fd, (off_t)0, SEEK_SET) == (off_t)-1)
		print_error("Error: Cannot reset file offset");

	print_elf_header(&header);

	if (close(fd) == -1)
		print_error("Error: Cannot close file");

	return (0);
}

