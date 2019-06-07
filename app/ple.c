#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void fromcursortoend(int index, char *contents, int cursor, void *data);

void ple(text txt) { process_forward(txt, fromcursortoend, NULL); }

static void fromcursortoend(int index, char *contents, int cursor, void *data) {
  assert(contents != NULL);

  UNUSED(index);
  UNUSED(cursor);
  UNUSED(data);

  if (cursor != -1 && contents[cursor] != '\0') {
    int a = strlen(contents) - cursor;
    char str[a];

    for (int i = 0; i < a; i++) {
      str[i] = contents[i + cursor];
    }
    str[a] = '\0';

    printf("%s", str);
    if (str[strlen(str) - 1] != '\n')
      printf("\n");
  }
}
