/**
 * editor.c -- строковый текстовый редактор
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "text/text.h"

#define MAXLINE 255

int main() {
  char cmdline[MAXLINE + 1];
  char *cmd;
  char *arg;

  /* Создаем объект для представления текста */
  text txt = create_text();

  /* Цикл обработки команд */
  while (1) {
    printf("ed > ");

    /* Получаем команду */
    fgets(cmdline, MAXLINE, stdin);

    /* Извлекаем имя команды */
    if ((cmd = strtok(cmdline, " \n")) == NULL) {
      continue;
    }
    /* Распознаем поддерживаемую команду */

    /* Завершаем работу редактора */
    if (strcmp(cmd, "quit") == 0) {
      fprintf(stderr, "Bye!\n");
      break;
    }

    /* Загружаем содержимое файла, заданного параметром */
    if (strcmp(cmd, "load") == 0) {
      if ((arg = strtok(NULL, " \n")) == NULL) {
        fprintf(stderr, "Usage: load filename\n");
      } else
        load(txt, arg);
      continue;
    }

    /* Сохраняем текст в указанный файл */
    if (strcmp(cmd, "save") == 0) {
      if ((arg = strtok(NULL, " \n")) == NULL) {
        fprintf(stderr, "Usage: save filename\n");
      } else {
        save(txt, arg);
      }
      continue;
    }

    /* Выводим текст */
    if (strcmp(cmd, "show") == 0) {
      show(txt);
      continue;
    }

    /* Выводим содержимое с нумерацией строк */
    if (strcmp(cmd, "shownum") == 0) {
      shownum(txt);
      continue;
    }

    /* Меняем позицию курсора на заданную */
    if (strcmp(cmd, "mwcrsr") == 0) {
        char *line = strtok(NULL, " \n"), *position = strtok(NULL, " \n");
        if (line && position)
            mwcrsr(txt, atoi(line), atoi(position));
        else
            printf("Usage: mwcrsr line position\n");
        continue;
    }

    if (strcmp(cmd, "getcrsr") == 0) {
        getcrsr(txt);
        continue;
    }

    /* Перемещаем курсор на один символ вправо, если это возможно */
    if (strcmp(cmd, "mcf") == 0) {
        mcf(txt);
        continue;
    }

    /* Перемещаем курсор в конец предыдущего слова, если это возможно */
    if (strcmp(cmd, "mpweb") == 0) {
        mpweb(txt);
        continue;
    }

    /* Печатаем от курсора до конца строки */
    if (strcmp(cmd, "ple") == 0) {
        ple(txt);
        continue;
    }

    /* Если команда не известна */
    fprintf(stderr, "Unknown command: %s\n", cmd);
  }

  return 0;
}
