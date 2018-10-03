//
//  ResultCode.h
//  VTap
//
//  Created by V-Key on 6/3/15.
//  Copyright (c) 2015 vkey. All rights reserved.
//

//TA TAG
//enum TA_TYPE {typeA, typeB};
//
//enum TA_TYPE categoryForIndex(int index) {
//    if (index > 1 && index < 4) {
//        return typeA;
//    } else {
//        return typeB;
//    }
//}

typedef enum{
    PKI_TOKEN = 3,
    OTP_TOKEN = 2,
    UNKNOWN_TOKEN
}TokenType;

//SETUP VTAP
#define VTAP_SETUP_SUCCESS                              40200

#define VGUARD_FAILED                                   40202
#define VOS_FAILED                                      40203
#define VTAP_TOKEN_LOAD_FAILED                          40204
#define VTAP_SETUP_FAILED                               40205

//CHECK DEVICE COMPATIBILITY
#define VTAP_WHITE_LISTED_DEVICE                        40300
#define VTAP_BLACK_LISTED_DEVICE                        40301
#define VTAP_GREY_LISTED_DEVICE                         40302
#define VTAP_GET_DEVICE_LIST_FAILED                     40303

//SEND DEVICE INFO
#define VTAP_SEND_DEVICE_INFO_SUCCESS                   40400
#define VTAP_SEND_DEVICE_INFO_FAILED                    40401

//SEND ERROR LOGS
#define VTAP_SEND_TROUBLESHOOTING_LOGS_SUCCESS          40502
#define VTAP_SEND_TROUBLESHOOTING_LOGS_FAILED           40503

#define VTAP_TOKEN_DOWNLOAD_SUCCESS                     40600
#define VTAP_ERROR_INVALID_PROVISIONING_INFO            40601
#define VTAP_ERROR_INVALID_TOKEN_SERIAL                 40602
#define VTAP_ERROR_INVALID_ACTIVATION_PIN               40603
#define VTAP_TOKEN_DOWNLOAD_FAILED                      40604
#define VTAP_TOKEN_NOT_FOUND                            40605 // Http error code 204 > Firmware Not found or already provisioned
#define VTAP_TOKEN_BAD_REQUEST                          40606 // Http error code 400 > Invalid DFP# or Invalid Customer
#define VTAP_TOKEN_INVALID_DFP                          40607
#define VTAP_LOAD_FIRMWARE_SUCCESS                      40608
#define VTAP_TOKEN_UNZIP_FAILED                         40609
#define VTAP_TOKEN_PROCESSING_FAILED                    40610
#define VTAP_LOAD_FIRMWARE_FAILED                       40611
#define VTAP_LOAD_TOKEN_SUCCESS                         40612
#define VTAP_LOAD_TOKEN_FAILED                          40613
#define VTAP_UNLOAD_TOKEN_SUCCESS                       40614
#define VTAP_UNLOAD_TOKEN_FAILED                        40615
#define VTAP_SET_DEFAULT_TOKEN_SUCCESS                  40616
#define VTAP_TOKEN_NOT_PROVISIONED                      40617
#define VTAP_REMOVE_TOKEN_SUCCESS                       40618
#define VTAP_REMOVE_TOKEN_FAILED                        40619

//USER PIN REGISTRATION
#define VTAP_CREATE_PIN_SUCCESS                         40700
#define VTAP_CREATE_PIN_FAILED                          40701
#define VTAP_PIN_ALREADY_EXIST                          40702
#define VTAP_CHECK_PIN_SUCCESS                          40800
#define VTAP_CHECK_PIN_FAILED                           40801
#define VTAP_VOS_LOCKED                                 40802
#define VTAP_CHANGE_PIN_SUCCESS                         40900
#define VTAP_CHANGE_PIN_FAILED                          40901
#define VTAP_CHANGE_INCORRECT_PIN_FAILED                40902

//TRANSACTION
#define VTAP_SET_OTP_LENGTH_SUCCESS                     41000
#define VTAP_SET_OTP_LENGTH_FAILED                      41001
#define VTAP_GENERATE_TOTP_FAILED                       41002
#define VTAP_TOTP_UNSUPPORTED_KEY_OPTION                41003
#define VTAP_GENERATE_CR_FAILED                         41004
#define VTAP_CR_UNSUPPORTED_MSG_LENGTH                  41005
#define VTAP_GENERATE_TXS_FAILED                        41006
#define VTAP_TXS_UNSUPPORTED_MSG_LENGTH                 41007
#define VTAP_UNSUPPORTED_OTP_LENGTH                     41008
#define VTAP_INCORRECT_API_CALL_SEQUENCE                41009
#define VTAP_TIME_FAILURE                               41010

//OTHER RESULTS
#define VTAP_INVALID_INPUT                              41011
#define VTAP_ERROR_CONNECTION_FAILED                    41012   //INTERNET CONNECTION
#define VTAP_INVALID_API_SEQUENCE                       41013

//PKI
#define VTAP_PUSH_NOTIFICATION_REGISTRATION_SUCCESS     41014
#define VTAP_PUSH_NOTIFICATION_REGISTRATION_FAILED      41015

// Trigger push notification
#define VTAP_PKI_TRIGGER_SEND_CERT_SUCCESS              41140
#define VTAP_PKI_TRIGGER_SEND_CERT_FAILED               41141

#define VTAP_PKI_CSR_REGISTRATION_SUCCESS               41100
#define VTAP_PKI_CSR_REGISTRATION_FAILED                41101

#define VTAP_PKI_AUTHENTICATION_SUCCESS                 41102
#define VTAP_PKI_AUTHENTICATION_FAILED                  41103
#define VTAP_PKI_AUTHENTICATION_CERT_NOT_AVAILABLE      41105

#define VTAP_PKI_DOC_SIGNING_SUCCESS                    41106
#define VTAP_PKI_DOC_SIGNING_FAILED                     41107
#define VTAP_PKI_DOC_SIGNING_CERT_NOT_AVAILABLE         41109

#define VTAP_PKI_MESSAGE_DOWNLOAD_FAILED                41111

#define VTAP_PKI_CERT_DOWNLOAD_SUCCESS                  41112
#define VTAP_PKI_CERT_DOWNLOAD_FAILED                   41113

#define VTAP_PKI_CHECK_PIN_SUCCESS                      41114
#define VTAP_PKI_CHECK_PIN_FAILED                       41115

#define VTAP_PKI_CHANGE_PIN_SUCCESS                     41116
#define VTAP_PKI_CHANGE_PIN_FAILED                      41117
#define VTAP_PKI_CHANGE_INCORRECT_PIN_FAILED            41119

#define VTAP_PKI_CERT_VERIFICATION_FAILED               41123

#define VTAP_VMESSAGE_DECRYPT_MSG_FAILED                41125

#define VTAP_VMESSAGE_SEND_ACK_SUCCESS                  41126
#define VTAP_VMESSAGE_SEND_ACK_FAILED                   41127
#define VTAP_PKI_VMESSAGE_CERT_NOT_AVAILABLE            41121

#define VTAP_PKI_AUTHENTICATION_REJECTION_SUCCESS       41160
#define VTAP_PKI_AUTHENTICATION_REJECTION_FAILED        41161


// New Rest APIs
#define VTAP_CREATE_ADDITIONAL_DATA_SUCCESS                         40903
#define VTAP_INVALID_FORMAT                                         41018
#define VTAP_DISABLE_ADDITIONAL_DATA                                41019
#define VTAP_CREATE_ADDITIONAL_MESSAGE_TYPE_SUCCESS                 41020

//Netrust
#define VTAP_GENERATE_ECC_CSR_WITH_ALIAS_SUCCEEDED                  42000
#define VTAP_GENERATE_ECC_CSR_WITH_ALIAS_FAILED                     42001
#define VTAP_DELETE_ECC_KEY_WITH_ALIAS_SUCCEEDED                    42002
#define VTAP_DELETE_ECC_KEY_WITH_ALIAS_FAILED                       42003
#define VTAP_ECC_SIGN_WITH_ALIAS_SUCCEEDED                          42004
#define VTAP_ECC_SIGN_WITH_ALIAS_FAILED                             42005
#define VTAP_ECC_VERIFY_WITH_ALIAS_SUCCEEDED                        42006
#define VTAP_ECC_VERIFY_WITH_ALIAS_FAILED                           42007
#define VTAP_ADD_CERT_WITH_ALIAS_SUCCEEDED                          42008
#define VTAP_ADD_CERT_WITH_ALIAS_FAILED                             42009
#define VTAP_GET_CERT_WITH_ALIAS_SUCCEEDED                          42010
#define VTAP_GET_CERT_WITH_ALIAS_FAILED                             42011
#define VTAP_DELETE_CERT_WITH_ALIAS_SUCCEEDED                       42012
#define VTAP_DELETE_CERT_WITH_ALIAS_FAILED                          42013
#define VTAP_GET_KEY_ALIASES_SUCCEEDED                              42014
#define VTAP_GET_KEY_ALIASES_FAILED                                 42015
#define VTAP_GET_CERT_ALIASES_SUCCEEDED                             42016
#define VTAP_GET_CERT_ALIASES_FAILED                                42017
#define VTAP_IS_KEY_ALIAS_FAILED                                    42018
#define VTAP_IS_CERT_ALIAS_FAILED                                   42019
#define VTAP_RESET_TOKEN_FIRMWARE_SUCCEEDED                         42020
#define VTAP_RESET_TOKEN_FIRMWARE_FAILED                            42021
#define VTAP_ALIAS_FOUND                                            42022
#define VTAP_ALIAS_NOT_FOUND                                        42023
//#endif
