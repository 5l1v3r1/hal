#include "netlist/gate_library/gate_type/gate_type.h"

#include "core/log.h"

gate_type::gate_type(const std::string& name)
{
    static u32 next_id = 1;

    m_id        = next_id++;
    m_name      = name;
    m_base_type = base_type::combinatorial;
}

u32 gate_type::get_id() const
{
    return m_id;
}

std::string gate_type::to_string() const
{
    return m_name;
}

std::ostream& operator<<(std::ostream& os, const gate_type& gt)
{
    return os << gt.to_string();
}

bool gate_type::operator==(const gate_type& other) const
{
    bool equal = m_id == other.get_id();
    equal &= m_name == other.get_name();
    equal &= m_base_type == other.get_base_type();
    equal &= m_input_pins == other.get_input_pins();
    equal &= m_input_pin_groups == other.get_input_pin_groups();
    equal &= m_output_pins == other.get_output_pins();
    equal &= m_output_pin_groups == other.get_output_pin_groups();
    equal &= m_functions == other.get_boolean_functions();
    equal &= this->do_compare(other);

    return equal;
}

bool gate_type::operator!=(const gate_type& other) const
{
    return !(*this == other);
}

bool gate_type::do_compare(const gate_type& other) const
{
    UNUSED(other);
    return true;
}

void gate_type::add_input_pin(std::string pin_name)
{
    if (const auto& it = std::find(m_input_pins.begin(), m_input_pins.end(), pin_name); it != m_input_pins.end())
    {
        log_warning("gate_type", "input pin with name '{}' does already exist for gate type '{}', ignoring pin", pin_name, m_name);
        return;
    }

    m_input_pins.push_back(pin_name);
    m_input_pin_groups.emplace(pin_name, std::vector<u32>(0));
}

void gate_type::add_input_pins(const std::vector<std::string>& pin_names)
{
    for (const auto& pin_name : pin_names)
    {
        if (const auto& it = std::find(m_input_pins.begin(), m_input_pins.end(), pin_name); it != m_input_pins.end())
        {
            log_warning("gate_type", "input pin with name '{}' does already exist for gate type '{}', ignoring pin", pin_name, m_name);
            continue;
        }

        m_input_pins.push_back(pin_name);
        m_input_pin_groups.emplace(pin_name, std::vector<u32>(0));
    }
}

void gate_type::add_input_pin_group(std::string group_name, std::vector<u32> range)
{
    if (const auto& it = m_input_pin_groups.find(group_name); it != m_input_pin_groups.end())
    {
        log_warning("gate_type", "input pin group with name '{}' does already exist for gate type '{}', ignoring group", group_name, m_name);
        return;
    }

    m_input_pin_groups.emplace(group_name, range);
    for (const auto& index : range)
    {
        m_input_pins.push_back(group_name + "(" + std::to_string(index) + ")");
    }
}

void gate_type::add_output_pin(std::string pin_name)
{
    if (const auto& it = std::find(m_output_pins.begin(), m_output_pins.end(), pin_name); it != m_output_pins.end())
    {
        log_warning("gate_type", "output pin with name '{}' does already exist for gate type '{}', ignoring pin", pin_name, m_name);
        return;
    }

    m_output_pins.push_back(pin_name);
    m_output_pin_groups.emplace(pin_name, std::vector<u32>(0));
}

void gate_type::add_output_pins(const std::vector<std::string>& pin_names)
{
    for (const auto& pin_name : pin_names)
    {
        if (const auto& it = std::find(m_output_pins.begin(), m_output_pins.end(), pin_name); it != m_output_pins.end())
        {
            log_warning("gate_type", "output pin with name '{}' does already exist for gate type '{}', ignoring pin", pin_name, m_name);
            continue;
        }

        m_output_pins.push_back(pin_name);
        m_output_pin_groups.emplace(pin_name, std::vector<u32>(0));
    }
}

void gate_type::add_output_pin_group(std::string group_name, std::vector<u32> range)
{
    if (const auto& it = m_output_pin_groups.find(group_name); it != m_output_pin_groups.end())
    {
        log_warning("gate_type", "output pin group with name '{}' does already exist for gate type '{}', ignoring group", group_name, m_name);
        return;
    }

    m_output_pin_groups.emplace(group_name, range);
    for (const auto& index : range)
    {
        m_output_pins.push_back(group_name + "(" + std::to_string(index) + ")");
    }
}

void gate_type::add_boolean_function(std::string pin_name, boolean_function bf)
{
    if (const auto& it = std::find(m_output_pins.begin(), m_output_pins.end(), pin_name); it == m_output_pins.end())
    {
        log_warning("gate_type", "pin '{}' of gate type '{}' is not an output pin, ignoring boolean function", pin_name, m_name);
        return;
    }

    m_functions.emplace(pin_name, bf);
}

void gate_type::add_boolean_functions(const std::map<std::string, boolean_function>& functions)
{
    for (const auto& function : functions)
    {
        if (const auto& it = std::find(m_output_pins.begin(), m_output_pins.end(), function.first); it == m_output_pins.end())
        {
            log_warning("gate_type", "pin '{}' of gate type '{}' is not an output pin, ignoring boolean function", function.first, m_name);
            continue;
        }

        m_functions.insert(function);
    }
}

std::string gate_type::get_name() const
{
    return m_name;
}

gate_type::base_type gate_type::get_base_type() const
{
    return m_base_type;
}

std::vector<std::string> gate_type::get_input_pins() const
{
    return m_input_pins;
}

std::map<std::string, std::vector<u32>> gate_type::get_input_pin_groups() const
{
    return m_input_pin_groups;
}

std::vector<std::string> gate_type::get_output_pins() const
{
    return m_output_pins;
}

std::map<std::string, std::vector<u32>> gate_type::get_output_pin_groups() const
{
    return m_output_pin_groups;
}

std::unordered_map<std::string, boolean_function> gate_type::get_boolean_functions() const
{
    return m_functions;
}
