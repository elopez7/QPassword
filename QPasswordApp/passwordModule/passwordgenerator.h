#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <QObject>
#include <QProperty>
#include <QtQml/qqmlregistration.h>

class PasswordGenerator : public QObject
{
    Q_OBJECT
    QML_NAMED_ELEMENT(PasswordComponent)

    Q_PROPERTY(QString generatedPassword
                   READ getGeneratedPassword
                       WRITE setGeneratedPassword
                           BINDABLE bindablePassword
                               FINAL)

    Q_PROPERTY(int passwordLength
                   READ passwordLength
                       WRITE setPasswordLength
                           BINDABLE bindablePasswordLength
                               FINAL)

    Q_PROPERTY(bool useLowerCase
                   READ useLowerCase
                       WRITE setUseLowerCase
                           BINDABLE bindableLowerCase
                               FINAL)

    Q_PROPERTY(bool useUpperCase
                   READ useUpperCase
                       WRITE setUseUpperCase
                           BINDABLE bindableUpperCase
                               FINAL)

    Q_PROPERTY(bool useNumbers
                   READ useNumbers
                       WRITE setUseNumbers
                           BINDABLE bindableNumbers
                               FINAL)

    Q_PROPERTY(bool useSpecialCharacters
                   READ useSpecialCharacters
                       WRITE setUseSpecialCharacters
                           BINDABLE bindableSpecialChars
                               FINAL)
public:


    Q_INVOKABLE void printPassword();

    QBindable<QString> bindablePassword() {return &m_generatedPassword;}
    QBindable<bool> bindableLowerCase() {return &m_useLowerCase;}
    QBindable<bool> bindableUpperCase() {return &m_useUpperCase;}
    QBindable<bool> bindableNumbers() {return &m_useNumbers;}
    QBindable<bool> bindableSpecialChars() {return &m_useSpecialCharacters;}
    QBindable<int> bindablePasswordLength() {return &m_passwordLength;}

    explicit PasswordGenerator(QObject *parent = nullptr);

    QString getGeneratedPassword() const;
    void setGeneratedPassword(const QString &newGeneratedPassword);

    bool useLowerCase() const;
    void setUseLowerCase(bool newUseLowerCase);

    bool useSpecialCharacters() const;
    void setUseSpecialCharacters(bool newUseSpecialCharacters);

    bool useNumbers() const;
    void setUseNumbers(bool newUseNumbers);

    bool useUpperCase() const;
    void setUseUpperCase(bool newUseUpperCase);

    int passwordLength() const;
    void setPasswordLength(int newPasswordLength);

signals:
    void generatedPasswordChanged();
    void useLowerCaseChanged();

private:
    QString m_alphabet;
    void makeAlphabet();
    void updatePassword();

    Q_OBJECT_BINDABLE_PROPERTY(PasswordGenerator,
                               QString,
                               m_generatedPassword,
                               &PasswordGenerator::generatedPasswordChanged);

    Q_OBJECT_BINDABLE_PROPERTY(PasswordGenerator,
                               bool,
                               m_useLowerCase,
                               &PasswordGenerator::useLowerCaseChanged);

    Q_OBJECT_BINDABLE_PROPERTY(PasswordGenerator,
                               bool,
                               m_useUpperCase,
                               &PasswordGenerator::useLowerCaseChanged);

    Q_OBJECT_BINDABLE_PROPERTY(PasswordGenerator,
                               bool,
                               m_useNumbers,
                               &PasswordGenerator::useLowerCaseChanged);

    Q_OBJECT_BINDABLE_PROPERTY(PasswordGenerator,
                               bool,
                               m_useSpecialCharacters,
                               &PasswordGenerator::useLowerCaseChanged);

    Q_OBJECT_BINDABLE_PROPERTY(PasswordGenerator,
                               int,
                               m_passwordLength,
                               &PasswordGenerator::useLowerCaseChanged);


};

#endif // PASSWORDGENERATOR_H
