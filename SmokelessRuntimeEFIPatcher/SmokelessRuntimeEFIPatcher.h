#ifndef _HEADER_H_
#define _HEADER_H_

#include <Uefi.h>
#include <PiDxe.h>
#include <Guid/FileInfo.h>
#include <Guid/FileSystemInfo.h>
#include <Guid/GlobalVariable.h>
#include <Library/DebugLib.h>
#include <Library/DevicePathLib.h>
#include <Library/UefiApplicationEntryPoint.h>
//#include <Library/UefiDriverEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiHiiServicesLib.h>           //Needed for strings
#include <Library/MemoryAllocationLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/PrintLib.h>
#include <Library/PeCoffGetEntryPointLib.h>
#include <Protocol/FirmwareVolume2.h>
#include <Protocol/BlockIo.h>
#include <Protocol/DevicePath.h>
#include <Protocol/LoadedImage.h>
#include <Protocol/SimpleFileSystem.h>
#include <Protocol/FormBrowser2.h>
#include <Protocol/FormBrowserEx.h>
#include <Protocol/FormBrowserEx2.h>
#include <Protocol/RegularExpressionProtocol.h>   //Needed for regex
#include <Protocol/HiiPackageList.h>              //       for strings
#include <Library/HiiLib.h>                       //       for fonts and strings
#include <Library/UefiRuntimeServicesTableLib.h>  //       for gRT
#include <Library/ShellLib.h>                     //       for FindNextFile
#include <Library/ShellCommandLib.h>              //       for HandleParsingLib' CatSDumpHex
#include <Library/HandleParsingLib.h>             //       for FindLoadedImageFromShellIndex
#include <Guid/ZeroGuid.h>                        //       for gZeroGuid def

#include "OpCode.h"

//C2220 suppression due to 'declaration of identifier hiding global declaration'
#pragma warning(disable:4459)

#define SREP_LANG_VARIABLE_GUID                 { 0x257ea3f4, 0xc447, 0x4b22, 0xbb, 0x1c, 0x37, 0x9b, 0x7f, 0xde, 0x28, 0x3e };
#define EFI_FIRMWARE_VOLUME_PROTOCOL_GUID       { 0x389f751f, 0x1838, 0x4388, 0x83, 0x90, 0xcd, 0x81, 0x54, 0xbd, 0x27, 0xf8 };
#define APTIO_SETUP_UTILITY_PACKAGE_LIST_GUID   { 0x899407d7, 0x99fe, 0x43d8, 0x9a, 0x21, 0x79, 0xec, 0x32, 0x8c, 0xac, 0x21 };
#define INSYDE_SETUP_UTILITY_PACKAGE_LIST_GUID  { 0xfe3542fe, 0xc1d3, 0x4ef8, 0x65, 0x7c, 0x80, 0x48, 0x60, 0x6f, 0xf6, 0x70 };

CONST UINT8 DevicePathHeaderUint[] = { HARDWARE_DEVICE_PATH, HW_VENDOR_DP, (UINT8)sizeof(VENDOR_DEVICE_PATH), 0x00 };
CONST UINT8 Edk2ifrSetupStringsPointerUint[] = { EFI_HII_PACKAGE_STRINGS, 0x34, 0x00, 0x00, 0x00, 0x34 };
CONST UINT8 Edk2ifrHiiBinPointerHeaderUint[] = { EFI_HII_PACKAGE_FORMS, EFI_IFR_FORM_SET_OP, 0xA7 };
CONST UINT8 Edk1ifrHiiBinPointerHeaderUint[] = { 0x03, 0x00, EFI_IFR_FORM_SET_OP, 0x24 };

EFI_GUID gEfiFirmwareVolumeProtocolGuid = EFI_FIRMWARE_VOLUME_PROTOCOL_GUID;
EFI_GUID SREPLangVariableGuid = SREP_LANG_VARIABLE_GUID;
EFI_GUID FvProtocolGuid;
EFI_HII_HANDLE HiiHandleSREP;
EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *Console = NULL;
EFI_FILE *LogFile = NULL;
CHAR16 Log[0x200];
CONST UINTN GenericBufferSize = 0x200;

extern VOID LogToFile(IN EFI_FILE *LogFile, IN CHAR16 *String);
extern UINTN PrintConsoleSREP(IN CONST CHAR16 *Format, ...);

#endif
