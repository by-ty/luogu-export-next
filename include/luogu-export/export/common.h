// SPDX-License-Identifier: LGPL-3.0-or-later
// Copyright (C) 2026 by-ty
//
// This file is part of luogu-export-next
// (https://github.com/by-ty/luogu-export-next), a fork of luogu-export
// (https://github.com/sacharei/luogu-export) which is licensed under the
// MIT License (Copyright (c) 2026 sacharei); see the "Original MIT License"
// section in the LICENSE file.
//
// luogu-export-next is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published
// by the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version. See the LICENSE file or
// https://www.gnu.org/licenses/lgpl-3.0.html for the full license text.
//
// luogu-export-next is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
// License for more details.

// include/luogu-export/export/common.h
#ifndef LUOGU_EXPORT_EXPORT_COMMON_H
#define LUOGU_EXPORT_EXPORT_COMMON_H

#include <string>
#include <vector>
#include "luogu-export/contents/problem.h"

namespace luogu
{
    // -M / -L 共用的筛选条件
    struct ExportFilter
    {
        std::vector<std::string> tags;       // 标签：多个取“且”（题目必须全部包含）
        std::vector<int> difficulties;       // 难度：多个取“或”，已展开为单个数字
        std::vector<std::string> types;      // 题目类型：B / P，空表示全部
        std::string lang = "zh-CN";          // 题面语言：zh-CN / en
        std::string show = "11";             // 显示开关：第 1 位=难度，第 2 位=标签
    };

    // 从缓存 latest.ndjson 中筛选题目并按题号排序（-M / -L 共用）。
    // resolved_tags 可选：返回解析后的标签名（数字 ID 已翻译成名称），
    // 用于在导出文件头描述筛选条件。
    bool select_problems(const ExportFilter &filter,
                         std::vector<problem::Problem> &problems,
                         std::vector<std::string> *resolved_tags,
                         std::string &error);

    // 生成筛选条件的中文说明；无筛选时返回空字符串
    std::string describe_filter(const ExportFilter &filter,
                                const std::vector<std::string> &resolved_tags);
}

#endif // LUOGU_EXPORT_EXPORT_COMMON_H
