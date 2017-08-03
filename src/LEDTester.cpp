// -*- C++ -*-
/*!
 * @file  LEDTester.cpp
 * @brief hoge
 * @date $Date$
 *
 * $Id$
 */

#include "LEDTester.h"

// Module specification
// <rtc-template block="module_spec">
static const char* ledtester_spec[] =
  {
    "implementation_id", "LEDTester",
    "type_name",         "LEDTester",
    "description",       "hoge",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.r", "0.5",
    "conf.default.g", "0.5",
    "conf.default.b", "0.5",
    // Widget
    "conf.__widget__.r", "text",
    "conf.__widget__.g", "text",
    "conf.__widget__.b", "text",
    // Constraints
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
LEDTester::LEDTester(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_outOut("dp_name", m_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
LEDTester::~LEDTester()
{
}



RTC::ReturnCode_t LEDTester::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("dp_name", m_outOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("r", m_r, "0.5");
  bindParameter("g", m_g, "0.5");
  bindParameter("b", m_b, "0.5");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t LEDTester::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LEDTester::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LEDTester::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LEDTester::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LEDTester::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t LEDTester::onExecute(RTC::UniqueId ec_id)
{
  m_out.data.length(3);
  m_out.data[0] = m_r;
  m_out.data[1] = m_g;
  m_out.data[2] = m_b;
  setTimestamp(m_out);
  m_outOut.write();
  return RTC::RTC_OK;
}


/*
RTC::ReturnCode_t LEDTester::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LEDTester::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LEDTester::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LEDTester::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LEDTester::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void LEDTesterInit(RTC::Manager* manager)
  {
    coil::Properties profile(ledtester_spec);
    manager->registerFactory(profile,
                             RTC::Create<LEDTester>,
                             RTC::Delete<LEDTester>);
  }
  
};


