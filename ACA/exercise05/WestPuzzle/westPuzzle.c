// Complize : gcc -o wp.exe westPuzzle.c libpng.a -lz -I ../libWorkingFiles/libpng/include

#include "pngfileio.c"

void process_file(void)
{
    for (int y = 0; y < height; y++)
    {
        png_byte *row = row_pointers[y];
        for (int x = 0; x < width; x++)
        {
            png_byte *ptr = &(row[x * 4]);

            ptr[0] = ptr[2] < 16 ? ptr[2] * 16 : 0;  //red
            ptr[1] = 0; // green
            ptr[2] = 0; // blue
        }
    }
}

void main(int argc, char **argv)
{
    if (argc < 3)
        abort_("Usage: program_name <file_in> <file_out>");

    read_png_file(argv[1]);
    process_file();
    write_png_file(argv[2]);
}