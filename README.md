# meojson

[English](#CPP_JSON_Parser_Generator)

## C++ JSON解析/生成库

### 简介

- `meojson`是一个`非常快`的C++ JSON解析库，O(n)级复杂度，解析速度比腾讯RapidJson快12倍以上！

    ```bash
    # 测试方法
    cd test/parse/
    chmod a+x test.sh
    ./test.sh
    ```

    ![image](parse_test.png)

- `meojson`也是一个使用方便的C++ JSON生成库，可以使用各种语法糖优雅地生成JSON

    ```c++
    json::value json;
    json["hello"] = "meojson";
    json["Pi"] = 3.1416;

    json["arr"] = json::array(
        {"a", "b", "c"}
    );

    json["obj"] = json::object(
        {
            {"obj_key1", "aaa"},
            {"obj_key2", 123},
            {"obj_key3", true}
        }
    );
    json["obj_another"]["child"]["grand"] = "i am grand";

    // Output "{"obj_another":{"child":{"grand":"i am grand"}},"obj":{"obj_key3":true,"obj_key2":123,"obj_key1":"aaa"},"arr":["a","b","c"],"Pi":3.141600,"hello":"meojson"}"
    std::cout << json.to_string() << std::endl;
    ```

- `meojson`需要编译器支持C++17标准

### 安装

1. 构建动态库并安装

    ```bash
    make release
    sudo make install
    ```

2. 在您的项目，添加`-lmeojson`编译选项中
3. 集成代码并使用

### 集成

```c++
/***
 * from sample/sample.cpp
***/

#include <iostream>

#include "json.h"

int main()
{

    /*** Parse ***/
    {
        std::cout << "****** Parsing ****** " << std::endl;
        std::string content = R"(
        {
            "prject": {
                "name": "meojson",
                "list": [ 
                    1, 2, 3
                ]
            }
        }
        )";
        //std::cout << content << std::endl;

        auto &&[ret, value] = json::parser::parse(content);

        if (ret)
        {
            // Output "meojson"
            std::cout << value["prject"]["name"].as_string() << std::endl;
            // Output 2
            std::cout << value["prject"]["list"][1].as_integer() << std::endl;
        }
        else
        {
            std::cout << "parse failed" << std::endl;
        }
    }

    std::cout << std::endl;

    /*** Generate ***/
    {
        std::cout << "****** Generating ******" << std::endl;

        json::value json;
        json["hello"] = "meojson";
        json["Pi"] = 3.1416;

        json["arr"] = json::array(
            {"a", "b", "c"});
        json["obj"] = json::object(
            {{"obj_key1", "aaa"},
             {"obj_key2", 123},
             {"obj_key3", true}});
        json["obj_another"]["child"]["grand"] = "i am grand";

        // Output "{"obj_another":{"child":{"grand":"i am grand"}},"obj":{"obj_key3":true,"obj_key2":123,"obj_key1":"aaa"},"arr":["a","b","c"],"Pi":3.141600,"hello":"meojson"}"
        std::cout << json.to_string() << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
```

## CPP_JSON_Parser_Generator

### Introduction

- `meojson` is a `very fast` json parserfor C++, O(n) Complexity, 1200% faster than Tecent's RapidJson.

    ```bash
    # How to test
    cd test/parse/
    chmod a+x test.sh
    ./test.sh
    ```

    ![image](parse_test.png)

- `meojson` is also an easy-to-use C++ JSON generation library that can use various syntactic sugars to elegantly generate JSON

    ```c++
    json::value json;
    json["hello"] = "meojson";
    json["Pi"] = 3.1416;

    json["arr"] = json::array(
        {"a", "b", "c"}
    );

    json["obj"] = json::object(
        {
            {"obj_key1", "aaa"},
            {"obj_key2", 123},
            {"obj_key3", true}
        }
    );
    json["obj_another"]["child"]["grand"] = "i am grand";

    // Output "{"obj_another":{"child":{"grand":"i am grand"}},"obj":{"obj_key3":true,"obj_key2":123,"obj_key1":"aaa"},"arr":["a","b","c"],"Pi":3.141600,"hello":"meojson"}"
    std::cout << json.to_string() << std::endl;
    ```

- `meojson` requires the compiler to support the C++17 standard

### Installation

1. Build dynamic library and install

    ```bash
    make release
    sudo make install
    ```

2. Add `-lmeojson` compilation option to your project
3. Integrate code and enjoy it!

### Sample

```c++
/***
 * from sample/sample.cpp
***/

#include <iostream>

#include "json.h"

int main()
{

    /*** Parse ***/
    {
        std::cout << "****** Parsing ****** " << std::endl;
        std::string content = R"(
        {
            "prject": {
                "name": "meojson",
                "list": [ 
                    1, 2, 3
                ]
            }
        }
        )";
        //std::cout << content << std::endl;

        auto &&[ret, value] = json::parser::parse(content);

        if (ret)
        {
            // Output "meojson"
            std::cout << value["prject"]["name"].as_string() << std::endl;
            // Output 2
            std::cout << value["prject"]["list"][1].as_integer() << std::endl;
        }
        else
        {
            std::cout << "parse failed" << std::endl;
        }
    }

    std::cout << std::endl;

    /*** Generate ***/
    {
        std::cout << "****** Generating ******" << std::endl;

        json::value json;
        json["hello"] = "meojson";
        json["Pi"] = 3.1416;

        json["arr"] = json::array(
            {"a", "b", "c"});
        json["obj"] = json::object(
            {{"obj_key1", "aaa"},
             {"obj_key2", 123},
             {"obj_key3", true}});
        json["obj_another"]["child"]["grand"] = "i am grand";

        // Output "{"obj_another":{"child":{"grand":"i am grand"}},"obj":{"obj_key3":true,"obj_key2":123,"obj_key1":"aaa"},"arr":["a","b","c"],"Pi":3.141600,"hello":"meojson"}"
        std::cout << json.to_string() << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
```
