#include <stdio.h>
#include <elf.h>

void print_magic(unsigned char *e_ident) {
    printf("ELF Header:\n");
    printf("  Magic: ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", e_ident[i]);
    }
    printf("\n");
}

void print_class(unsigned char e_ident) {
    const char *class = "INVALID";
    switch (e_ident) {
        case ELFCLASSNONE: class = "None"; break;
        case ELFCLASS32: class = "ELF32"; break;
        case ELFCLASS64: class = "ELF64"; break;
    }
    printf("  Class:                           %s\n", class);
}

void print_data(unsigned char e_ident) {
    const char *data = "INVALID";
    switch (e_ident) {
        case ELFDATANONE: data = "None"; break;
        case ELFDATA2LSB: data = "2's complement, little endian"; break;
        case ELFDATA2MSB: data = "2's complement, big endian"; break;
    }
    printf("  Data:                            %s\n", data);
}

void print_version(unsigned char e_ident) {
    const char *version = "INVALID";
    switch (e_ident) {
        case EV_NONE: version = "None"; break;
        case EV_CURRENT: version = "Current"; break;
    }
    printf("  Version:                         %s\n", version);
}

void print_osabi(unsigned char e_ident) {
    const char *osabi = "UNIX - System V";
    switch (e_ident) {
        case ELFOSABI_NONE: osabi = "UNIX - System V"; break;
        case ELFOSABI_SYSV: osabi = "UNIX - System V"; break;
        case ELFOSABI_HPUX: osabi = "UNIX - HP-UX"; break;
        case ELFOSABI_NETBSD: osabi = "UNIX - NetBSD"; break;
        case ELFOSABI_LINUX: osabi = "UNIX - Linux"; break;
        case ELFOSABI_SOLARIS: osabi = "UNIX - Solaris"; break;
        case ELFOSABI_IRIX: osabi = "UNIX - IRIX"; break;
        case ELFOSABI_FREEBSD: osabi = "UNIX - FreeBSD"; break;
        case ELFOSABI_TRU64: osabi = "UNIX - TRU64"; break;
        case ELFOSABI_ARM: osabi = "ARM"; break;
        case ELFOSABI_STANDALONE: osabi = "Standalone App"; break;
    }
    printf("  OS/ABI:                          %s\n", osabi);
}

void print_type(Elf32_Half e_type) {
    const char *type;
    switch (e_type) {
        case ET_NONE: type = "NONE"; break;
        case ET_REL: type = "REL"; break;
        case ET_EXEC: type = "EXEC"; break;
        case ET_DYN: type = "DYN"; break;
        case ET_CORE: type = "CORE"; break;
        default: type = "UNKNOWN"; break;
    }
    printf("  Type:                            %s\n", type);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    Elf32_Ehdr ehdr;

    if (argc < 2) {
        printf("Usage: %s <ELF binary>\n", argv[0]);
        return 1;
    }

    if ((fp = fopen(argv

