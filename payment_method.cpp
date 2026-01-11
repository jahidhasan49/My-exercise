#include <iostream>

using namespace std;

class BKash {
    private:
        string bKashAccountName;
        string bKashMobileNumber;
        double bKashBalance;
        double bKashChargeOfPayment;
    public:
        BKash() {
            this->bKashBalance = 0.0;
            this->bKashChargeOfPayment = 1;
        }

        BKash(string bKashAccountName, string bKashMobileNumber, double bKashBalance, double bKashChargeOfPayment) {
            this->bKashAccountName = bKashAccountName;
            this->bKashMobileNumber = bKashMobileNumber;
            this->bKashBalance = bKashBalance;
            this->bKashChargeOfPayment = bKashChargeOfPayment;
        }

        string getBKashAccountName() {
            return this->bKashAccountName;
        }

        void setBKashAccountName(string bKashAccountName) {
            this->bKashAccountName = bKashAccountName;
        }

        string getBKashMobileNumber() {
            return this->bKashMobileNumber;
        }

        void setBKashMobileNumber(string bKashMobileNumber) {
            this->bKashMobileNumber = bKashMobileNumber;
        }

        double getBKashBalance() {
            return this->bKashBalance;
        }

        void setBKashBalance(double bKashBalance) {
            this->bKashBalance = bKashBalance;
        }

        double getBKashChargeOfPayment() {
            return this->bKashChargeOfPayment;
        }

        void setBKashChargeOfPayment(double bKashChargeOfPayment) {
            this->bKashChargeOfPayment = bKashChargeOfPayment;
        }

        void display() {
            cout << "BKash Account Details:" << endl;
            cout << "Name: " << this->bKashAccountName << endl;
            cout << "Mobile Number: " << this->bKashMobileNumber << endl;
            cout << "Balance: " << this->bKashBalance << endl;
        }

        bool bKashPaymentChecker(double paymentAmount) {
            double paymentAmountWithCharge = paymentAmount * this->bKashChargeOfPayment;

            if(this->bKashBalance >= paymentAmountWithCharge) {
                cout << "You have sufficient balance in BKash to perform the payment" << endl;
                return true;
            }
            else {
                cout << "You don't have sufficient balance in BKash to perform the payment" << endl;
                return false;
            }
        }

        double bKashPay(double paymentAmount) {
            double paymentAmountWithCharge = paymentAmount * this->bKashChargeOfPayment;
            this->bKashBalance -= paymentAmountWithCharge;

            return paymentAmountWithCharge;
        }
};

class Nogod {
    private:
        string nogodAccountName;
        string nogodMobileNumber;
        double nogodBalance;
        double nogodChargeOfPayment;
    public:
        Nogod() {
            this->nogodBalance = 0.0;
            this->nogodChargeOfPayment = 1;
        }

        Nogod(string nogodAccountName, string nogodMobileNumber, double nogodBalance, double nogodChargeOfPayment) {
            this->nogodAccountName = nogodAccountName;
            this->nogodMobileNumber = nogodMobileNumber;
            this->nogodBalance = nogodBalance;
            this->nogodChargeOfPayment = nogodChargeOfPayment;
        }

        string getNogodAccountName() {
            return this->nogodAccountName;
        }

        void setNogodAccountName(string nogodAccountName) {
            this->nogodAccountName = nogodAccountName;
        }

        string getNogodMobileNumber() {
            return this->nogodMobileNumber;
        }

        void setNogodMobileNumber(string nogodMobileNumber) {
            this->nogodMobileNumber = nogodMobileNumber;
        }

        double getNogodBalance() {
            return this->nogodBalance;
        }

        void setNogodBalance(double nogodBalance) {
            this->nogodBalance = nogodBalance;
        }

        double getNogodChargeOfPayment() {
            return this->nogodChargeOfPayment;
        }

        void setNogodChargeOfPayment(double nogodChargeOfPayment) {
            this->nogodChargeOfPayment = nogodChargeOfPayment;
        }

        void display() {
            cout << "Nogod Account Details:" << endl;
            cout << "Name: " << this->nogodAccountName << endl;
            cout << "Mobile Number: " << this->nogodMobileNumber << endl;
            cout << "Balance: " << this->nogodBalance << endl;
        }

        bool nogodPaymentChecker(double paymentAmount) {
            double paymentAmountWithCharge = paymentAmount * this->nogodChargeOfPayment;

            if(this->nogodBalance >= paymentAmountWithCharge) {
                cout << "You have sufficient balance in Nogod to perform the payment" << endl;
                return true;
            }
            else {
                cout << "You don't have sufficient balance in Nogod to perform the payment" << endl;
                return false;
            }
        }

        double nogodPay(double paymentAmount) {
            double paymentAmountWithCharge = paymentAmount * this->nogodChargeOfPayment;
            this->nogodBalance -= paymentAmountWithCharge;

            return paymentAmountWithCharge;
        }
};

class SSLCommerce : private BKash, private Nogod {
    private:
        double sSLCChargeOfPayment;
    public:
        SSLCommerce(): BKash(), Nogod() {
            this->sSLCChargeOfPayment = 1;
        }

        SSLCommerce(string bKashAccountName, string bKashMobileNumber, double bKashBalance, double bKashChargeOfPayment,
                    string nogodAccountName, string nogodMobileNumber, double nogodBalance, double nogodChargeOfPayment,
                    double sSLCChargeOfPayment):
                    BKash(bKashAccountName, bKashMobileNumber, bKashBalance, bKashChargeOfPayment),
                    Nogod(nogodAccountName, nogodMobileNumber, nogodBalance, nogodChargeOfPayment) {
            this->sSLCChargeOfPayment = sSLCChargeOfPayment;
        }

        double getSSLChargeOfPayment() {
            return this->sSLCChargeOfPayment;
        }

        void setSSLChargeOfPayment(double sSLCChargeOfPayment) {
            this->sSLCChargeOfPayment = sSLCChargeOfPayment;
        }

        void sSLCPay(double paymentAmount, string paymentMethod) {
            double paymentAmountWithCharge = paymentAmount * this->sSLCChargeOfPayment;
            if(paymentMethod == "BKash") {
                if(bKashPaymentChecker(paymentAmountWithCharge)) {
                    double totalPayment = bKashPay(paymentAmountWithCharge);

                    cout << "BKash Payment successful!!!" << endl;
                    cout << totalPayment << " BDT is paid from BKash Account: " << getBKashMobileNumber()
                         << ". Your current balance: " << getBKashBalance() << "." << endl;
                }
                else {
                    cout << "BKash Payment unsuccessful!!!" << endl;
                }
            }
            else if(paymentMethod == "Nogod") {
                if(nogodPaymentChecker(paymentAmount)) {
                    double totalPayment = nogodPay(paymentAmountWithCharge);

                    cout << "Nogod Payment successful!!!" << endl;
                    cout << totalPayment << " BDT is paid from Nogod Account: " << getNogodMobileNumber()
                         << ". Your current balance: " << getNogodBalance() << "." << endl;
                }
                else {
                    cout << "Nogod Payment unsuccessful!!!" << endl;
                }
            }
            else {
                cout << "Invalid Payment Method" << endl;
            }
        }
};

int main() {
    string bKashAccountName, bKashMobileNumber, nogodAccountName, nogodMobileNumber;
    double bKashBalance, bKashChargeOfPayment, nogodBalance, nogodChargeOfPayment, sSLCChargeOfPayment;

    cout << "Please enter your BKash Account Info (Name, Mobile No., Balance, Payment Charge):" << endl;
    cin.ignore();

    getline(cin, bKashAccountName);
    getline(cin, bKashMobileNumber);
    bKashBalance = 5000;
    bKashChargeOfPayment = 1;

    cout << "Please enter your Nogod Account Info (Name, Mobile No., Balance, Payment Charge):" << endl;
    cin.ignore();
    getline(cin, nogodAccountName);
    getline(cin, nogodMobileNumber);
    nogodBalance = 7000;
    nogodChargeOfPayment = 1;

    sSLCChargeOfPayment = 1.012;

    SSLCommerce sslCommerce(bKashAccountName, bKashMobileNumber, bKashBalance, bKashChargeOfPayment,
                            nogodAccountName, nogodMobileNumber, nogodBalance, nogodChargeOfPayment,
                            sSLCChargeOfPayment);

    int choice;
    double billingAmountWithoutCharge;
    string paymentMethod;

    cout << "Press 1: for BKash Payment" << endl;
    cout << "Press 2: for Nogod Payment" << endl;

    cin.ignore();
    cin >> choice;

    cout << "Enter billing amount without charge: " << endl;

    cin.ignore();
    cin >> billingAmountWithoutCharge;

    if(choice == 1) {
        paymentMethod = "BKash";
        sslCommerce .sSLCPay(billingAmountWithoutCharge, paymentMethod);
    }
    else if(choice == 2) {
        paymentMethod = "Nogod";
        sslCommerce.sSLCPay(billingAmountWithoutCharge, paymentMethod);
    }
    else {
        cout << "Invalid Payment Method" << endl;
    }


    return 0;
}