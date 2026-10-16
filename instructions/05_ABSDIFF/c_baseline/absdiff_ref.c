#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

/*
 * ABSDIFF(絕對差)
 * 規格: rd = |rs1 - rs2|
 * 其中減法與絕對值都以 32-bit wrap 計算。
 *
 * 這表示先將 rs1-rs2 做 modulo 2^32 的減法，
 * 再將該 32-bit 值取絕對值；若正負號位為 1，則補碼取反+1。
 *
 * 回傳型別使用 uint32_t，因為結果是 32-bit bit-pattern，
 * 也可直接寫回暫存器。
 */
static uint32_t absdiff_wrap32(int32_t rs1, int32_t rs2)
{
    uint32_t diff = (uint32_t)rs1 - (uint32_t)rs2;  // 32-bit wrap 減法

    // 若 diff 的 sign bit 為 1，表示它對應到負數，取補碼絕對值
    if ((diff >> 31u) != 0u) {
        diff = (~diff) + 1u;
    }

    return diff;
}

int main(void)
{
    struct {
        int32_t a;
        int32_t b;
        uint32_t expect;
    } tests[] = {
        { 3, 10, 7u },
        { 10, 3, 7u },
        { 0, 0, 0u },
        { -5, 3, 8u },
        { 5, -3, 8u },
        { INT32_MIN, 1, 2147483647u },
        { 0, INT32_MIN, 2147483648u }
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        uint32_t result = absdiff_wrap32(tests[i].a, tests[i].b);

        printf("(%" PRId32 ", %" PRId32 ") -> %" PRIu32, tests[i].a, tests[i].b, result);

        if (result != tests[i].expect) {
            printf("  [FAIL: expected %" PRIu32 "]\n", tests[i].expect);
            return 1;
        }

        printf("  [OK]\n");
    }

    return 0;
}
