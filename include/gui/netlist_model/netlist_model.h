/*
 * MIT License
 *
 * Copyright (c) 2019 Chair for Embedded Security, Ruhr-University Bochum
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*
#ifndef NETLIST_MODEL_H
#define NETLIST_MODEL_H

#include "def.h"

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

class module_netlist_item;
class gate_netlist_item;
class net_netlist_item;

class netlist_model : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit netlist_model(QObject* parent = nullptr);
    ~netlist_model() override;

    // PURE VIRTUAL
    QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex& index) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;

    // VIRTUAL
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    netlist_item* get_item(const QModelIndex& index) const;
    QModelIndex get_index(const netlist_item* const item) const;

    void add_module(const u32 id, const u32 parent_module);
    void add_gate(const u32 id, const u32 parent_module);
    void add_net(const u32 id, const u32 parent_module);

    void remove_module(const u32 id);
    void remove_gate(const u32 id);
    void remove_net(const u32 id);

private:
    module_netlist_item* m_root_item;

    QMap<u32, module_netlist_item*> m_module_items;
    QMap<u32, gate_netlist_item*> m_gate_items;
    QMap<u32, net_netlist_item*> m_net_items;
};

#endif // NETLIST_MODEL_H
*/