#include <iostream>
#include <string>

enum class IdType
{
    Passport,
    DriverLicense
};

struct Passport
{
    Passport(std::string country, std::string issuer)
        : m_country(country), m_issuer(issuer) {}
    std::string m_country;
    std::string m_issuer;
};

struct DriverLicense
{
    DriverLicense(std::string state, bool glasses)
        : m_state(state), m_glasses(glasses) {}
    std::string m_state;
    bool m_glasses;
};

union Data {
    Data(std::string country, std::string issuer)
        : passport(country, issuer) {}
    Data(std::string state, bool glasses)
        : driverlicense(state, glasses) {}
    Passport passport;
    DriverLicense driverlicense;
    ~Data() {}
};

struct Traveler
{
    Traveler(std::string _name,
             std::string _id,
             std::string _country,
             std::string _issuer)
        : m_data(_country, _issuer)
    {
        m_name = _name;
        m_id = _id;
        m_type = IdType::Passport;
    }

    Traveler(std::string _name, std::string _id, std::string _state, bool _glasses)
        : m_data(_state, _glasses)
    {
        m_name = _name;
        m_id = _id;
        m_type = IdType::DriverLicense;
    }

    std::string m_name;
    std::string m_id;
    IdType m_type;
    Data m_data;
};

int main()
{

    using namespace std::literals;
    Traveler person("Bob", "Dylan", "South Carolina"s, true);
    std::cout << person.m_data.driverlicense.m_state << '\n';
    std::cout << std::boolalpha << person.m_data.driverlicense.m_glasses << '\n';

    //Data d("one"s, "two"s);
    //std::cout << d.passport.m_issuer << '\n';

    Traveler person2("John", "Fry", std::string("USA"), "New York"s);

    std::cout << person2.m_data.passport.m_issuer << '\n';
}