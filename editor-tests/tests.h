#pragma once

#include <limits.h>
#include <string.h>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C" {
    #include "../app/text/_text.h"
    #include "../app/text/text.h"
    #include "../app/common.h"
}

static void func(int index, char *contents, int cursor, void *data);

static void func(int index, char *contents, int cursor, void *data) {
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

    assert(contents != NULL);
    assert(cursor != -1);
}

using namespace testing;

TEST(test1, tests)
{
    EXPECT_NE(create_objects(), nullptr);
}

TEST(test2, tests)
{
    text txt = create_text();
    load(txt, "<filename>");

    EXPECT_EQ(txt->length, 0);
}

TEST(test3, tests)
{
    text txt = create_text();
    load(txt, "/etc/shadow");

    EXPECT_EQ(txt->length, 0);
}

TEST(test4, tests)
{
    text txt = create_text();
    load(txt, "input.txt");
    show(txt);
    shownum(txt);

    EXPECT_EQ(txt->cursor->position, 5);
}

TEST(test5, tests)
{
    text txt = create_text();
    show(txt);
    shownum(txt);

    EXPECT_EQ(txt->cursor->position, 0);
}

TEST(test6, tests)
{
    text txt = create_text();
    load(txt, "input.txt");

    EXPECT_NE(txt->length, 0);
    save(txt, "test.txt");
    EXPECT_NE(fopen("test.txt", "r"), nullptr);
}

TEST(test7, tests)
{
    text txt = create_text();
    const char* contents = "TEST";
    load(txt, "input.txt");

    EXPECT_NO_FATAL_FAILURE(append_line(txt, contents););
    EXPECT_NE(txt->length, 0);
}

TEST(test8, tests)
{
    text txt = create_text();
    char contents[10000];
    load(txt, "input.txt");
    for (; strlen(contents) < 10000; strcat(contents, "TEST"));

    EXPECT_EXIT(append_line(txt, contents), ::testing::ExitedWithCode(EXIT_FAILURE), "");
}

TEST(test9, tests)
{
    text txt = create_text();
    load(txt, "input.txt");
    mwcrsr(txt, 0, 2);

    EXPECT_EQ(txt->cursor->position, 1);
}

TEST(test10, tests)
{
    text txt = create_text();
    load(txt, "input.txt");
    mwcrsr(txt, -1, -1);

    EXPECT_EQ(txt->cursor->position, 0);
}

TEST(test11, tests)
{
    text txt = create_text();
    load(txt, "long.txt");
    delete_line(txt, 3);

    EXPECT_EQ(txt->length, 2);
    delete_line(txt, 1);
    EXPECT_EQ(txt->length, 1);
}

TEST(test12, tests)
{
    text txt = create_text();
    load(txt, "long.txt");
    delete_line(txt, 2);

    EXPECT_EQ(txt->length, 2);
}

TEST(test13, tests)
{
    text txt = create_text();
    load(txt, "long.txt");

    EXPECT_DEATH(delete_line(txt, 10), "");
    EXPECT_DEATH(delete_line(txt, -1), "");
}

TEST(test14, tests)
{
    text txt = create_text();
    delete_line(txt, 1);

    EXPECT_EQ(txt->begin, nullptr);
    EXPECT_EQ(txt->end, nullptr);
}

TEST(test15, tests)
{
    text txt = create_text();
    load(txt, "input.txt");
    delete_line(txt, 1);

    EXPECT_EQ(txt->begin, nullptr);
    EXPECT_EQ(txt->end, nullptr);
}

TEST(test16, tests)
{
    text txt = create_text();
    load(txt, "input.txt");
    remove_all(txt);

    EXPECT_NE(txt, nullptr);
    EXPECT_EQ(txt->length, 0);
}

TEST(test17, tests)
{
    text txt = nullptr;
    remove_all(txt);

    EXPECT_EQ(txt, nullptr);
}

TEST(test18, tests)
{
    text txt = create_text();
    load(txt, "input.txt");
    ple(txt);
    mwcrsr(txt, 0, 0);

    EXPECT_STREQ(txt->cursor->line->contents, "TEST\n");
}

TEST(test19, tests) {
    text txt = create_text();
    load(txt, "input.txt");

    mpweb(txt);
    EXPECT_NO_FATAL_FAILURE(process_forward(txt, func, NULL));
}

TEST(test20, tests)
{
    text txt = create_text();
    load(txt, "input.txt");
    mwcrsr(txt, 0, 0);
    ple(txt);

    EXPECT_NO_FATAL_FAILURE(process_forward(txt, func, NULL));
}

TEST(test21, tests)
{
    text txt = create_text();
    load(txt, "input.txt");
    ple(txt);

    EXPECT_NO_FATAL_FAILURE(process_forward(txt, func, NULL));
}

TEST(test22, tests)
{
    text txt = create_text();
    load(txt, "input.txt");
    mcf(txt);

    EXPECT_EQ(txt->cursor->position, 5);
}

TEST(test23, tests)
{
    text txt = create_text();
    load(txt, "input.txt");
    mwcrsr(txt, 0, 0);
    mcf(txt);

    EXPECT_EQ(txt->cursor->position, 1);
}

TEST(test24, tests) {
    text txt = create_text();
    load(txt, "input.txt");
    mwcrsr(txt, 2, 2);

    mpweb(txt);
    EXPECT_NO_FATAL_FAILURE(process_forward(txt, func, NULL));
}
