//
// This project is unlicensed, you are free to use and modify any of these examples for your own needs.
//
// source code: https://github.com/WestleyR/c-examples
//

#include <stdio.h>
#include <string.h>
#include <getopt.h>

#define SCRIPT_VERSION "v1.0.0-beta-2, Nov 9, 2019"

void print_version() {
  printf("Version: %s\n", SCRIPT_VERSION);
}

void print_usage(const char* name) {
  printf("Usage: %s [option] <in-file> <out-file>\n", name);
  printf("\n");
  printf("Options:\n");
  printf("  -b, --binary    convert to ascii binary\n");
  printf("  -a, --ascii     convert from ascii binary\n");
  printf("  -h, --help      print help menu\n");
  printf("  -V, --version   print version\n");
  printf("\n");
  printf("File controls:\n");
  printf("  -,  --stdin   use stdin as input\n");
  printf("  -O, --stdout  use stdout as output\n");
  printf("\n");
}

int convert_txt_to_bin(const char *in, const char* out) {
  FILE *fp_in;
  FILE *fp_out;
  int c;

  fp_in = fopen(in, "rb");
  fp_out = fopen(out, "w");

  if (fp_in == NULL) {
    fprintf(stderr, "Failed to open: %s\n", in);
    perror(in);
    return(1);
  }

  if (fp_out == NULL) {
    fprintf(stderr, "Failed to open: %s\n", out);
    perror(out);
    return(1);
  }

  printf("Writing binary file to: %s...\n", out);

  while ((c = fgetc(fp_in)) != EOF) {
    for (int i = 0; i <= 7; i++) {
      if (c& (1 << (7 - i) )) {
        fprintf(fp_out, "%d", 1);
      } else {
        fprintf(fp_out, "%d", 0);
      }
    }
  }

  fclose(fp_in);
  fclose(fp_out);
  printf("Done.\n");

  return(0);
}


char bytes_to_char(unsigned char* bytes) {
  char ret = 0;

  for (int i = 0; i < 8; i++) {
    if (bytes[i] == '1') {
      ret |= (1 << (7 - i));
    } else {
      ret |= (0 << (7 - i));
    }
  }

  return(ret);
}

int convert_bin_txt(const char* in, const char *out){
  FILE *fp_in;
  FILE *fp_out;
  unsigned char out_char[8];
  int b;
  int byte_index = 0;

  fp_in = fopen(in, "r");
  fp_out = fopen(out, "wb");

  if (!fp_in) {
    printf("Unable to open file\n");
    return(1);
  }

  printf("Writing output ascii file to: %s...\n", out);

  while ((b = fgetc(fp_in)) != EOF) {
    out_char[byte_index] = b;
    byte_index++;
    if (byte_index == 8) {
      fprintf(fp_out, "%c", bytes_to_char(out_char));
      byte_index = 0;
    }
  }

  fclose(fp_in);
  fclose(fp_out);
  printf("Done.\n");

  return(0);
}



int main(int argc, char** argv) {
  int opt = 0;

  int to_binary = 0;
  int to_ascii = 0;

  int to_stdout = 0;

  char* from;
  char* to;

  static struct option long_options[] = {
    {"binary", no_argument, 0, 'b'},
    {"ascii", no_argument, 0, 'a'},
    {"stdout", no_argument, 0, '-'},
    {"help", no_argument, 0, 'h'},
    {"version", no_argument, 0, 'V'},
    {NULL, 0, 0, 0}
  };

  while ((opt = getopt_long(argc, argv, "ba-hV", long_options, 0)) != -1) {
    switch (opt) {
      case 'b':
        to_binary = 1;
        break;

      case 'a':
        to_ascii = 1;
        break;

      case '-':
        to_stdout = 1;
        break;

      case 'V':
        print_version();
        return(0);

      case 'h':
        print_usage(argv[0]);
        return(0);

      default:
        return(22);
    }
  }

  if (optind < argc) {
    if (argc - optind < 2 || argc - optind > 2) {
      fprintf(stderr, "Invallid file(s)\n");
      return(1);
    }
    from = argv[optind];
    to = argv[optind+1];
    //for (int i = optind; i < argc; i++) {
    //  path = argv[i];
    //}
  } else {
    fprintf(stderr, "No files, nothing to do...\n");
    return(123);
  }

  if (to_binary) {
    convert_txt_to_bin(from, to);
  } else if (to_ascii) {
    convert_bin_txt(from, to);
  } else {
    fprintf(stderr, "No action specifyed\n");
    return(22);
  }

  return(0);
}

// vim: tabstop=2 shiftwidth=2 expandtab
