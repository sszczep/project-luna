# HID Descriptor will be changed after every CubeMX code regeneration
# Run this script to change it back

DESC_SIZE_OLD = '#define HID_MOUSE_REPORT_DESC_SIZE                 74U'
DESC_SIZE_NEW = '#define HID_MOUSE_REPORT_DESC_SIZE                 45U'

REPORT_DESC_OLD = '''__ALIGN_BEGIN static uint8_t HID_MOUSE_ReportDesc[HID_MOUSE_REPORT_DESC_SIZE] __ALIGN_END =
{
  0x05,   0x01,
  0x09,   0x02,
  0xA1,   0x01,
  0x09,   0x01,

  0xA1,   0x00,
  0x05,   0x09,
  0x19,   0x01,
  0x29,   0x03,

  0x15,   0x00,
  0x25,   0x01,
  0x95,   0x03,
  0x75,   0x01,

  0x81,   0x02,
  0x95,   0x01,
  0x75,   0x05,
  0x81,   0x01,

  0x05,   0x01,
  0x09,   0x30,
  0x09,   0x31,
  0x09,   0x38,

  0x15,   0x81,
  0x25,   0x7F,
  0x75,   0x08,
  0x95,   0x03,

  0x81,   0x06,
  0xC0,   0x09,
  0x3c,   0x05,
  0xff,   0x09,

  0x01,   0x15,
  0x00,   0x25,
  0x01,   0x75,
  0x01,   0x95,

  0x02,   0xb1,
  0x22,   0x75,
  0x06,   0x95,
  0x01,   0xb1,

  0x01,   0xc0
};'''
REPORT_DESC_NEW = '''__ALIGN_BEGIN static uint8_t HID_MOUSE_ReportDesc[HID_MOUSE_REPORT_DESC_SIZE] __ALIGN_END =
{
  0x05, 0x01, // USAGE_PAGE (Generic Desktop)
  0x09, 0x06, // USAGE (Keyboard)
  0xa1, 0x01, // COLLECTION (Application)
  0x05, 0x07, // USAGE_PAGE (Keyboard)
  0x19, 0xe0, // USAGE_MINIMUM (Keyboard LeftControl)
  0x29, 0xe7, // USAGE_MAXIMUM (Keyboard Right GUI)
  0x15, 0x00, // LOGICAL_MINIMUM (0)
  0x25, 0x01, // LOGICAL_MAXIMUM (1)
  0x75, 0x01, // REPORT_SIZE (1)
  0x95, 0x08, // REPORT_COUNT (8)
  0x81, 0x02, // INPUT (Data,Var,Abs) //1 byte

  0x95, 0x01, // REPORT_COUNT (1)
  0x75, 0x08, // REPORT_SIZE (8)
  0x81, 0x03, // INPUT (Cnst,Var,Abs) //1 byte

  0x95, 0x06, // REPORT_COUNT (6)
  0x75, 0x08, // REPORT_SIZE (8)
  0x15, 0x00, // LOGICAL_MINIMUM (0)
  0x25, 0x65, // LOGICAL_MAXIMUM (101)
  0x05, 0x07, // USAGE_PAGE (Keyboard)
  0x19, 0x00, // USAGE_MINIMUM (Reserved (no event indicated))
  0x29, 0x65, // USAGE_MAXIMUM (Keyboard Application)
  0x81, 0x00, // INPUT (Data,Ary,Abs) //6 bytes

  0xc0 // END_COLLECTION
};'''

HEADER_FILE = "./Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc/usbd_hid.h"
SOURCE_FILE = "./Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.c"

def replace_in_file(filepath, old, new):
  with open(filepath, 'r+') as file:
    old_data = file.read()
    file.seek(0)
    new_data = old_data.replace(old, new)
    file.write(new_data)
    file.truncate()

# Replace content of header file
replace_in_file(HEADER_FILE, DESC_SIZE_OLD, DESC_SIZE_NEW)

# Replace content of source file
replace_in_file(SOURCE_FILE, REPORT_DESC_OLD, REPORT_DESC_NEW)