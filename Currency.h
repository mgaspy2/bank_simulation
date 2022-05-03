#pragma once

using namespace std;

enum currency_t {
    EURO,
    CZK,
    USD,
    AUD
};

static double exchangeRate(currency_t sendingAcc, currency_t receivingAcc) {
    // rates set 1.5.2022 from xCurrency mini app
    switch (sendingAcc) {
        case EURO:
            switch (receivingAcc) {
                case CZK:
                    return 24.59;
                case USD:
                    return 1.06;
                case AUD:
                    return 1.49;
            }
        case CZK:
            switch (receivingAcc) {
                case EURO:
                    return 0.041;
                case USD:
                    return 0.043;
                case AUD:
                    return 0.061;
            }
        case USD:
            switch (receivingAcc) {
                case EURO:
                    return 0.041;
                case CZK:
                    return 23.31;
                case AUD:
                    return 1.41;
            }
        case AUD:
            switch (receivingAcc) {
                case EURO:
                    return 0.67;
                case CZK:
                    return 16.49;
                case USD:
                    return 0.71;
            }
    }
    return 0;
}
