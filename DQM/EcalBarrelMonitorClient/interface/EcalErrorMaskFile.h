// $Id: EcalErrorMaskFile.h,v 1.5 2006/12/14 17:16:20 dellaric Exp $

/*!
  \file EcalErrorMaskFile.h
  \brief Error mask from text file
  \author B. Gobbo 
  \version $Revision: 1.5 $
  \date $Date: 2006/12/14 17:16:20 $
*/

#ifndef EcalErrorMaskFile_H
#define EcalErrorMaskFile_H

#include <string>
#include <map>
#include "OnlineDB/EcalCondDB/interface/MonCrystalStatusDat.h"
#include "OnlineDB/EcalCondDB/interface/MonPNStatusDat.h"
#include "OnlineDB/EcalCondDB/interface/EcalLogicID.h"

class EcalErrorMaskFile {

 public:

  static void readFile( std::string inFile ) throw( std::runtime_error );

  static void fetchDataSet( std::map< EcalLogicID, MonCrystalStatusDat>* fillMap ) throw( std::runtime_error );
  static void fetchDataSet( std::map< EcalLogicID, MonPNStatusDat>* fillMap ) throw( std::runtime_error );

 private:

  static bool done_;
  static std::string inFile_;
  static std::map<EcalLogicID, MonCrystalStatusDat> mapMCSD_;
  static std::map<EcalLogicID, MonPNStatusDat>      mapMPSD_;

  static void clearComments_( char* line );
  static void clearFinalBlanks_( char* line );

};

#endif // EcalErrorMaskFile_H
