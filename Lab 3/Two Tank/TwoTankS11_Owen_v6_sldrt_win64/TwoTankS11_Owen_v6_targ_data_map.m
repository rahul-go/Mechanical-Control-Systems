  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (TwoTankS11_Owen_v6_P)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% TwoTankS11_Owen_v6_P.Voltagefrombottomsensor_MaxMissedTicks
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% TwoTankS11_Owen_v6_P.Voltagefromtopsensor_MaxMissedTicks
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% TwoTankS11_Owen_v6_P.Voltageouttovalve_MaxMissedTicks
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% TwoTankS11_Owen_v6_P.Voltagefrombottomsensor_YieldWhenWaiting
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% TwoTankS11_Owen_v6_P.Voltagefromtopsensor_YieldWhenWaiting
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
	  ;% TwoTankS11_Owen_v6_P.Voltageouttovalve_YieldWhenWaiting
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% TwoTankS11_Owen_v6_P.Voltagefrombottomsensor_Channels
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% TwoTankS11_Owen_v6_P.Voltagefromtopsensor_Channels
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% TwoTankS11_Owen_v6_P.Voltageouttovalve_Channels
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% TwoTankS11_Owen_v6_P.Voltagefrombottomsensor_RangeMode
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% TwoTankS11_Owen_v6_P.Voltagefromtopsensor_RangeMode
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% TwoTankS11_Owen_v6_P.Voltageouttovalve_RangeMode
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
	  ;% TwoTankS11_Owen_v6_P.Voltagefrombottomsensor_VoltRange
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 6;
	
	  ;% TwoTankS11_Owen_v6_P.Voltagefromtopsensor_VoltRange
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 7;
	
	  ;% TwoTankS11_Owen_v6_P.Voltageouttovalve_VoltRange
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% TwoTankS11_Owen_v6_P.Biasbottomtankinches_Value
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% TwoTankS11_Owen_v6_P.Sensorgainbottomtankinchesvolt_Gain
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% TwoTankS11_Owen_v6_P.Sensorgaintoptankinchesvolt_Gain
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% TwoTankS11_Owen_v6_P.Toptankbiasinches_Value
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 3;
	
	  ;% TwoTankS11_Owen_v6_P.Desiredheightofbottomtank_Value
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 4;
	
	  ;% TwoTankS11_Owen_v6_P.Designvalveactuationvoltage_Value
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 5;
	
	  ;% TwoTankS11_Owen_v6_P.Designheightofbottomtank_Value
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 6;
	
	  ;% TwoTankS11_Owen_v6_P.KP_Gain
	  section.data(8).logicalSrcIdx = 24;
	  section.data(8).dtTransOffset = 7;
	
	  ;% TwoTankS11_Owen_v6_P.Integrator_IC
	  section.data(9).logicalSrcIdx = 25;
	  section.data(9).dtTransOffset = 8;
	
	  ;% TwoTankS11_Owen_v6_P.KI_Gain
	  section.data(10).logicalSrcIdx = 26;
	  section.data(10).dtTransOffset = 9;
	
	  ;% TwoTankS11_Owen_v6_P.KD_Gain
	  section.data(11).logicalSrcIdx = 27;
	  section.data(11).dtTransOffset = 10;
	
	  ;% TwoTankS11_Owen_v6_P.Man0Auto1_Gain
	  section.data(12).logicalSrcIdx = 28;
	  section.data(12).dtTransOffset = 11;
	
	  ;% TwoTankS11_Owen_v6_P.Valvebiasopening_Value
	  section.data(13).logicalSrcIdx = 29;
	  section.data(13).dtTransOffset = 12;
	
	  ;% TwoTankS11_Owen_v6_P.Valvegainopeningvolt_Gain
	  section.data(14).logicalSrcIdx = 30;
	  section.data(14).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (TwoTankS11_Owen_v6_B)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% TwoTankS11_Owen_v6_B.Voltagefrombottomsensor
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% TwoTankS11_Owen_v6_B.Voltagefromtopsensor
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% TwoTankS11_Owen_v6_B.Sum8
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% TwoTankS11_Owen_v6_B.Clock
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% TwoTankS11_Owen_v6_B.Sum4
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% TwoTankS11_Owen_v6_B.Sum1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% TwoTankS11_Owen_v6_B.KP
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% TwoTankS11_Owen_v6_B.Sum3
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% TwoTankS11_Owen_v6_B.Sum7
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% TwoTankS11_Owen_v6_B.Storedataeverysecond
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (TwoTankS11_Owen_v6_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% TwoTankS11_Owen_v6_DW.TimeStampA
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% TwoTankS11_Owen_v6_DW.LastUAtTimeA
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% TwoTankS11_Owen_v6_DW.TimeStampB
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% TwoTankS11_Owen_v6_DW.LastUAtTimeB
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% TwoTankS11_Owen_v6_DW.Voltagefrombottomsensor_PWORK
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% TwoTankS11_Owen_v6_DW.Voltagefromtopsensor_PWORK
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% TwoTankS11_Owen_v6_DW.Bottomtankheight_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% TwoTankS11_Owen_v6_DW.ToWorkspace_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% TwoTankS11_Owen_v6_DW.Toptankheight_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% TwoTankS11_Owen_v6_DW.Valveactuationvoltage_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
	  ;% TwoTankS11_Owen_v6_DW.Valveopening_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 6;
	
	  ;% TwoTankS11_Owen_v6_DW.Voltageouttovalve_PWORK
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3002054108;
  targMap.checksum1 = 3417541179;
  targMap.checksum2 = 1586690770;
  targMap.checksum3 = 964100368;

