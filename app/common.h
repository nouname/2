/**
 * common.h -- прототипы функций реализации команд редактора
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "data.h"
#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 *  Перемещает курсор на один символ вправо, если это возможно
 */
void mcf(text txt);

/**
 *  Перемещает курсор в конец предыдущего слова, если это возможно
 */
void mpweb(text txt);

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Выводит содержимое с нумерацией строк
 */
void shownum(text txt);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

/**
 * Сохраняет текст в указанный файл
 */
void save(text txt, char *filename);

/**
 * Перемещает курсор в указанную позицию
 */
void mwcrsr(text txt, int line, int position);

void getcrsr(text txt);

/**
 * Выводит часть строки от курсора до конца строки
 */
void ple(text txt);

/**
 * Возвращает текущую позицию курсора
 */
//void getcrsr(text txt);

#endif
