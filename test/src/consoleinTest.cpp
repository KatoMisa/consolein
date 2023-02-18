// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  consoleinTest.cpp
 * @brief ${rtcParam.description} (test code)
 *
 */
// </rtc-template>

#include "consoleinTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const consolein_spec[] =
#else
static const char* consolein_spec[] =
#endif
  {
    "implementation_id", "consoleinTest",
    "type_name",         "consoleinTest",
    "description",       "${rtcParam.description}",
    "version",           "1.0.0",
    "vendor",            "rsdlab",
    "category",          "Test",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
consoleinTest::consoleinTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_OutportIn("Outport", m_Outport)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
consoleinTest::~consoleinTest()
{
}



RTC::ReturnCode_t consoleinTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("Outport", m_OutportIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t consoleinTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t consoleinTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t consoleinTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t consoleinTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t consoleinTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t consoleinTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t consoleinTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t consoleinTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t consoleinTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t consoleinTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t consoleinTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool consoleinTest::runTest()
{
    return true;
}


extern "C"
{
 
  void consoleinTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(consolein_spec);
    manager->registerFactory(profile,
                             RTC::Create<consoleinTest>,
                             RTC::Delete<consoleinTest>);
  }
  
}
