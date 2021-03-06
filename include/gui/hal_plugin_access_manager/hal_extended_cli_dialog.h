//  MIT License
//
//  Copyright (c) 2019 Ruhr-University Bochum, Germany, Chair for Embedded Security. All Rights reserved.
//  Copyright (c) 2019 Marc Fyrbiak, Sebastian Wallat, Max Hoffmann ("ORIGINAL AUTHORS"). All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#ifndef HAL_EXTENDED_CLI_DIALOG_H
#define HAL_EXTENDED_CLI_DIALOG_H

#include "core/interface_cli.h"
#include "core/program_arguments.h"
#include <QBoxLayout>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <string>
#include <utility>
#include <vector>

class hal_extended_cli_dialog : public QDialog
{
    Q_OBJECT

public:
    hal_extended_cli_dialog(QString plugin_name, QWidget* parent = 0);

    program_arguments get_args();

private Q_SLOTS:
    void parse_arguments();

private:
    void setup(std::string plugin_name);
    QVBoxLayout* m_content_layout;
    QFormLayout* m_form_layout;
    QLabel* m_status_message;
    QDialogButtonBox* m_button_box;

    program_arguments m_args;
    std::shared_ptr<i_cli> m_plugin;

    std::vector<std::pair<QPushButton*, QLineEdit*>> m_vector;

    char** m_argv;
};

#endif    // HAL_EXTENDED_CLI_DIALOG_H
