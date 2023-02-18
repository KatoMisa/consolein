// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  consolein.cpp
 * @brief ${rtcParam.description}
 *
 */
// </rtc-template>

#include "consolein.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const consolein_spec[] =
#else
static const char* consolein_spec[] =
#endif
  {
    "implementation_id", "consolein",
    "type_name",         "consolein",
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
consolein::consolein(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_OutportOut("Outport", m_Outport)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
consolein::~consolein()
{
}



RTC::ReturnCode_t consolein::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("Outport", m_OutportOut);

  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t consolein::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t consolein::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t consolein::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t consolein::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t consolein::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t consolein::onExecute(RTC::UniqueId /*ec_id*/)
{
  std::cout << "Please input number: ";
  std::cin >> m_Outport.data;
  std::cout << "Sending to subscriber: " << m_Outport.data << std::endl;
  m_OutportOut.write();
 
  return RTC::RTC_OK;
}
//m_OutportOut("Outport", m_Outport)->m_Outport.data
//addOutPort("Outport", m_OutportOut);->m_OutportOut.write

//RTC::ReturnCode_t consolein::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t consolein::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t consolein::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t consolein::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t consolein::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void consoleinInit(RTC::Manager* manager)
  {
    coil::Properties profile(consolein_spec);
    manager->registerFactory(profile,
                             RTC::Create<consolein>,
                             RTC::Delete<consolein>);
  }
  
}
