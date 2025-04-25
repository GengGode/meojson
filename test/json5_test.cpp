#include <iostream>

#include "json5.hpp"
#include "json5_test.h"

bool parsing5();
bool parsing5_error();

bool test_json5()
{
    /*** parsing5 Json5 ***/

    if (!parsing5()) {
        return false;
    }

    if (!parsing5_error()) {
        return false;
    }

    return true;
}

bool parsing5()
{
    auto content_raw = R"(
// 这是一段json5格式的信息
{
  名字: "MistEO",                  /* key的引号可省略 */
  😊: '😄',                       // emoji为key
  thanks: 'ありがとう',             /* 单引号也可以表示字符串 */
  \u006Bey: ['value',],            // 普通字符和转义可以混用
  inf: +Infinity, nan: NaN,        // 数字可以以"+"开头
  fractional: .3, integer: 42.,    // 小数点作为起始/结尾
  byte_max: 0xff,                  // 十六进制数
  light_speed: +3e8,               // 科学计数法
  negative: -1,                    // 负数
  negative_double: -2.5,           // 负小数
}
)";
    std::string_view content = content_raw;
    std::string error_message;
    auto ret = json::parse5(content, &error_message);
    if (!ret) {
        std::cerr << "parsing5 failed" << std::endl;
        std::cerr << error_message << std::endl;
        return false;
    }
    {
        auto another_ret = json::parse5(content, &error_message);
        if (!another_ret) {
            std::cerr << "parsing5 failed" << std::endl;
            std::cerr << error_message << std::endl;
            return false;
        } // C-style strings can also be used as input.
    }
    json::value& value = ret.value(); // you can use rvalues if needed, like
                                      // `auto value = std::move(ret).value();`

    // Output: MistEO
    std::cout << value["名字"].as_string() << std::endl;
    // Output: value
    std::string str = (std::string)value["key"][0];
    std::cout << str << std::endl;
    // Output: 42
    std::cout << value["integer"].as_integer() << std::endl;
    // Output: -1
    std::cout << value["negative"].as_integer() << std::endl;
    // Output: -2.5
    std::cout << value["negative_double"].as_double() << std::endl;
    // Output: inf
    std::cout << value["inf"].as_double() << std::endl;

    // for more json::value usage, please refer to sample.cpp
    return true;
}

bool parsing5_error()
{
    std::string error_content = "{ error }";
    std::string error_msg;
    auto err_ret = json::parse5(error_content, &error_msg);
    if (!err_ret) {
        return true;
    }

    return false;
}
