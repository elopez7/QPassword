#include "passwordgenerator.h"
#include <random>
#include <QDebug>

PasswordGenerator::PasswordGenerator(QObject *parent)
    : QObject{parent}
{

}

QString PasswordGenerator::getGeneratedPassword() const
{
    return m_generatedPassword;
}

void PasswordGenerator::setGeneratedPassword(const QString &newGeneratedPassword)
{
    m_generatedPassword = newGeneratedPassword;
}

bool PasswordGenerator::useLowerCase() const
{
    return m_useLowerCase;
}

void PasswordGenerator::setUseLowerCase(bool newUseLowerCase)
{
    m_useLowerCase = newUseLowerCase;
}

bool PasswordGenerator::useSpecialCharacters() const
{
    return m_useSpecialCharacters;
}

void PasswordGenerator::setUseSpecialCharacters(bool newUseSpecialCharacters)
{
    m_useSpecialCharacters = newUseSpecialCharacters;
}

bool PasswordGenerator::useNumbers() const
{
    return m_useNumbers;
}

void PasswordGenerator::setUseNumbers(bool newUseNumbers)
{
    m_useNumbers = newUseNumbers;
}

bool PasswordGenerator::useUpperCase() const
{
    return m_useUpperCase;
}

void PasswordGenerator::setUseUpperCase(bool newUseUpperCase)
{
    m_useUpperCase = newUseUpperCase;
}

int PasswordGenerator::passwordLength() const
{
    return m_passwordLength;
}

void PasswordGenerator::setPasswordLength(int newPasswordLength)
{
    m_passwordLength = newPasswordLength;
}

void PasswordGenerator::printPassword()
{
    makeAlphabet();
}

void PasswordGenerator::makeAlphabet()
{
    using namespace Qt::Literals::StringLiterals;

    m_alphabet.clear();

    QString upperCaseLetters{u"ABCDEFGHIJKLMNOPQRSTUVWXYZ"_s};
    QString lowerCaseLetters{u"abcdefghijklmnopqrstuvwxyz"_s};
    QString numbers{u"0123456789"_s};
    QString specialCharacters{u"!@#$%^&*()_+-=;':\",./<>?~`"_s};

    if(m_useUpperCase) {
        m_alphabet.append(upperCaseLetters);
    }

    if(m_useLowerCase) {
        m_alphabet.append(lowerCaseLetters);
    }

    if(m_useNumbers) {
        m_alphabet.append(numbers);
    }

    if(m_useSpecialCharacters) {
        m_alphabet.append(specialCharacters);
    }

    updatePassword();
}

void PasswordGenerator::updatePassword()
{
    QString newPassword;
    if(m_alphabet.isEmpty()) {
        newPassword = QString();
    } else {

        std::random_device rd;
        std::mt19937 valueGenerator{rd()};
        std::uniform_int_distribution<> distribution(0, m_alphabet.size()-1);

        int codeValue{0};
        for(auto i = 0; i < m_passwordLength; i++)
        {
            codeValue = (distribution(valueGenerator));
            newPassword.append(m_alphabet.at(codeValue));
        }
    }

    if(m_generatedPassword == newPassword) {
        return; // unlikely!
    }
    m_generatedPassword = newPassword;
}
