#ifndef _gemsupervisor_GemSupervisorWeb_h
#define _gemsupervisor_GemSupervisorWeb_h

#include "xdaq/Application.h"
//#include "gem/base/GEMApplication.h"
#include "xdaq/WebApplication.h"

#include "xdata/String.h"
#include "xdata/UnsignedLong.h"
#include "xdata/UnsignedInteger32.h"

#include "uhal/uhal.hpp"

#include "xgi/framework/Method.h"
#include "xgi/framework/UIManager.h"
#include "cgicc/HTMLClasses.h"

typedef uhal::exception::exception uhalException;

namespace gemsupervisor {
  
  class GemSupervisorWeb: public xdaq::Application, public xgi::framework::UIManager, public xdata::ActionListener
  //class GemSupervisorWeb: public gem::base::GEMApplication, public xdata::ActionListener
  {
    public:
      XDAQ_INSTANTIATOR();
      
      GemSupervisorWeb(xdaq::ApplicationStub * s)
	throw (xdaq::exception::Exception);
      
      void Default(xgi::Input * in, xgi::Output * out )
	throw (xgi::exception::Exception);
      void Views(xgi::Input * in, xgi::Output * out )
	throw (xgi::exception::Exception);
      void setParameter(xgi::Input * in, xgi::Output * out)
	throw (xgi::exception::Exception);
      void writeUserRegs(xgi::Input * in, xgi::Output * out)
	throw (xgi::exception::Exception);
      void Read(xgi::Input * in, xgi::Output * out )
	throw (xgi::exception::Exception);
      void Write(xgi::Input * in, xgi::Output * out )
	throw (xgi::exception::Exception);

      void getTestReg();
      void setTestReg(uint32_t);

      void actionPerformed(xdata::Event& event);
      
    protected:
      xdata::UnsignedLong myParameter_;
      xdata::String myAction_;

      xdata::UnsignedInteger32 testReg_;
      xdata::UnsignedInteger32 boardID_;
      xdata::UnsignedInteger32 systemID_;
      xdata::UnsignedInteger32 systemFirmwareID_;
      xdata::UnsignedInteger32 userFirmwareID_;

      xdata::UnsignedInteger32 xreg_ctrl_;
      xdata::UnsignedInteger32 xreg_ctrl2_;
      xdata::UnsignedInteger32 xreg_status_;
      xdata::UnsignedInteger32 xreg_status2_;
      xdata::UnsignedInteger32 xreg_ctrl_sram_;
      xdata::UnsignedInteger32 xreg_status_sram_;
      xdata::UnsignedInteger32 xreg_spi_txdata_;
      xdata::UnsignedInteger32 xreg_spi_command_;
      xdata::UnsignedInteger32 xreg_spi_rxdata_;
      xdata::UnsignedInteger32 xreg_i2c_settings_;
      xdata::UnsignedInteger32 xreg_i2c_command_;
      xdata::UnsignedInteger32 xreg_i2c_reply_;
      xdata::UnsignedInteger32 xreg_sfp_phase_mon_ctrl_;
      xdata::UnsignedInteger32 xreg_sfp_phase_mon_stats_;
      xdata::UnsignedInteger32 xreg_fmc_phase_mon_ctrl_;
      xdata::UnsignedInteger32 xreg_fmc_phase_mon_stats_;

      xdata::UnsignedInteger32 xreg_mac_info1_;
      xdata::UnsignedInteger32 xreg_mac_info2_;
      xdata::UnsignedInteger32 xreg_ip_info_;

      xdata::UnsignedInteger32 xreg_sram1_;
      xdata::UnsignedInteger32 xreg_sram2_;
      xdata::UnsignedInteger32 xreg_icap_;

      std::vector<xdata::UnsignedInteger32 > xreg_users_;

    private:
      void initializeConnection();
      std::string registerToChar(xdata::UnsignedInteger32);
      std::string formatSystemID(xdata::UnsignedInteger32);
      std::string formatBoardID(xdata::UnsignedInteger32);
      std::string formatFW(xdata::UnsignedInteger32, int type);
      std::string getIPAddress();

      uhal::ConnectionManager *manager;
      uhal::HwInterface *hw;
      uhal::ValWord< uint32_t > r_test;
      uhal::ValWord< uint32_t > r_sysid;
      uhal::ValWord< uint32_t > r_boardid;
      uhal::ValWord< uint32_t > r_fwid;
      uhal::ValWord< uint32_t > r_ctrl;
      uhal::ValWord< uint32_t > r_ctrl2;
      uhal::ValWord< uint32_t > r_status;
      uhal::ValWord< uint32_t > r_status2;
      uhal::ValWord< uint32_t > r_ctrl_sram;
      uhal::ValWord< uint32_t > r_status_sram;
      uhal::ValWord< uint32_t > r_spi_txdata;
      uhal::ValWord< uint32_t > r_spi_command;
      uhal::ValWord< uint32_t > r_spi_rxdata;
      uhal::ValWord< uint32_t > r_i2c_settings;
      uhal::ValWord< uint32_t > r_i2c_command;
      uhal::ValWord< uint32_t > r_i2c_reply;
      uhal::ValWord< uint32_t > r_sfp_phase_mon_ctrl;
      uhal::ValWord< uint32_t > r_sfp_phase_mon_stats;
      uhal::ValWord< uint32_t > r_fmc_phase_mon_ctrl;
      uhal::ValWord< uint32_t > r_fmc_phase_mon_stats;

      uhal::ValWord< uint32_t > r_mac_info1;
      uhal::ValWord< uint32_t > r_mac_info2;
      uhal::ValWord< uint32_t > r_ip_info;

      uhal::ValWord< uint32_t > r_sram1;
      uhal::ValWord< uint32_t > r_sram2;
      uhal::ValWord< uint32_t > r_icap;                 

      std::vector<uhal::ValWord< uint32_t > > r_users;

  };
}
#endif
