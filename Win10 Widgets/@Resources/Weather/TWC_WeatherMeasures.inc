; Modified by Eclectic Tech Jan 18, 2020 :: Designed to work as an @include file for TWC weather data retrieval
; Modified by Kablion Feb. 15.02.2020


;===============================TEMPERATURE UNIT MEASURE==================================
[mTempUnit]
Measure=WebParser
Url=#URL#
RegExp=#TempUnit#
UpdateRate=#WeatherUpdateRate#
LogSubstringErrors=1
StringIndex=1
;DecodeCharacterReference=1
FinishAction=[!Log "Retrieved TempUnit."][!UpdateMeter *]
OnConnectErrorAction=[!HideMeterGroup WeatherMeters][!ShowMeter RetrievingWeather][!SetOption RefreshButton MouseLeaveAction "[!HideMeter RefreshButtonHoverEdge][!ShowMeter RefreshButtonEdge][!ShowMeter RefreshButtonCenter]"][!UpdateMeter RefreshButton][!ShowMeterGroup RefreshOverlay][!HideMeter RefreshButtonHoverEdge][!Log "Can not retrieve Temp Unit. No Connection." Error]
OnRegExpErrorAction=[!HideMeterGroup WeatherMeters][!ShowMeter RetrievingWeather][!SetOption RefreshButton MouseLeaveAction "[!HideMeter RefreshButtonHoverEdge][!ShowMeter RefreshButtonEdge][!ShowMeter RefreshButtonCenter]"][!UpdateMeter RefreshButton][!ShowMeterGroup RefreshOverlay][!HideMeter RefreshButtonHoverEdge][!Log "Can not read Temp Unit." Error]
DynamicVariables=1


;===============================LOCATION CITY MEASURE==================================

[mLocationText]
Measure=WebParser
Url=#URL#
RegExp=#Location#
UpdateRate=#WeatherUpdateRate#
LogSubstringErrors=0
StringIndex=1
DecodeCharacterReference=1
FinishAction=[!Log "Retrieved location."][!UpdateMeter *]
OnConnectErrorAction=[!HideMeterGroup WeatherMeters][!ShowMeter RetrievingWeather][!SetOption RefreshButton MouseLeaveAction "[!HideMeter RefreshButtonHoverEdge][!ShowMeter RefreshButtonEdge][!ShowMeter RefreshButtonCenter]"][!UpdateMeter RefreshButton][!ShowMeterGroup RefreshOverlay][!HideMeter RefreshButtonHoverEdge][!Log "Can not retrieved location. No Connection." Error]
OnRegExpErrorAction=[!HideMeterGroup WeatherMeters][!ShowMeter RetrievingWeather][!SetOption RefreshButton MouseLeaveAction "[!HideMeter RefreshButtonHoverEdge][!ShowMeter RefreshButtonEdge][!ShowMeter RefreshButtonCenter]"][!UpdateMeter RefreshButton][!ShowMeterGroup RefreshOverlay][!HideMeter RefreshButtonHoverEdge][!Log "Can not read location." Error]
DynamicVariables=1

;===============================NOW MEASURES==================================

[mNOW]
Measure=WebParser
Url=#URL#
RegExp=#NOW#
UpdateRate=#WeatherUpdateRate#
LogSubstringErrors=0
FinishAction=[!Log "Retrieved current conditions."][!UpdateMeasureGroup Current][!UpdateMeter *]
OnConnectErrorAction=[!HideMeterGroup WeatherMeters][!ShowMeter RetrievingWeather][!SetOption RefreshButton MouseLeaveAction "[!HideMeter RefreshButtonHoverEdge][!ShowMeter RefreshButtonEdge][!ShowMeter RefreshButtonCenter]"][!UpdateMeter RefreshButton][!ShowMeterGroup RefreshOverlay][!HideMeter RefreshButtonHoverEdge][!Log "Can not retrieved current conditions. No Connection." Error]
OnRegExpErrorAction=[!HideMeterGroup WeatherMeters][!ShowMeter RetrievingWeather][!SetOption RefreshButton MouseLeaveAction "[!HideMeter RefreshButtonHoverEdge][!ShowMeter RefreshButtonEdge][!ShowMeter RefreshButtonCenter]"][!UpdateMeter RefreshButton][!ShowMeterGroup RefreshOverlay][!HideMeter RefreshButtonHoverEdge][!Log "Can not read current conditions." Error]
DynamicVariables=1

[mUpdateText]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=1

[mUpdateTime]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=2

[mConditionIcon]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=3

[mTemperature]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=4

[mTemperatureSymbol]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=5

[mConditionText]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=6
DecodeCharacterReference=1

[mFeelsLikeText]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=7

[mFeelsLike]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=8

[mFeelsLikeSymbol]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=9

[mTemperatureMaximum]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=10

[mTemperatureMaximumSymbol]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=11

[mTemperatureMinimum]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=12
IfMatch=^$
IfMatchAction=[!HideMeter "MeterDay1Low"]
IfNotMatchAction=[]

[mTemperatureMinimumSymbol]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=13

[mTitle]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=14

[mWindText]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=15

[mWind]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=16

[mHumidityText]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=17

[mHumidity]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=18

[mHumiditySymbol]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=19

[mPressureText]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=20

[mPressure]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=21

[mVisibilityText]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=22

[mVisibility]
Measure=WebParser
Group=Current
Url=[mNOW]
StringIndex=23

;===============================FORECAST MEASURES==================================

[mForecast]
Measure=WebParser
Url=#URL3#
RegExp=#Forecast#
UpdateRate=#WeatherUpdateRate#
LogSubstringErrors=0
FinishAction=[!Log "Retrieved forecasts."][!UpdateMeasureGroup Forecasts][!UpdateMeter *]
OnConnectErrorAction=[!HideMeterGroup WeatherMeters][!ShowMeter RetrievingWeather][!SetOption RefreshButton MouseLeaveAction "[!HideMeter RefreshButtonHoverEdge][!ShowMeter RefreshButtonEdge][!ShowMeter RefreshButtonCenter]"][!UpdateMeter RefreshButton][!ShowMeterGroup RefreshOverlay][!HideMeter RefreshButtonHoverEdge][!Log "Can not retrieved forecasts. No Connection." Error]
OnRegExpErrorAction=[!HideMeterGroup WeatherMeters][!ShowMeter RetrievingWeather][!SetOption RefreshButton MouseLeaveAction "[!HideMeter RefreshButtonHoverEdge][!ShowMeter RefreshButtonEdge][!ShowMeter RefreshButtonCenter]"][!UpdateMeter RefreshButton][!ShowMeterGroup RefreshOverlay][!HideMeter RefreshButtonHoverEdge][!Log "Can not read forecasts." Error]
DynamicVariables=1

[mForecastWeekDay1]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=1

[mForecastConditionIcon1]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=2

[mForecastDate1]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=3

[mForecastCond1tionText1]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=4
DecodeCharacterReference=1

[mForecastPrecipitationPercent1]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=5

[mForecastPrecipitationPercentSymbol1]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=6

[mForecastWeekDay2]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=7

[mForecastConditionIcon2]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=8

[mForecastDate2]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=9

[mForecastConditionText2]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=10
DecodeCharacterReference=1

[mForecastTemperatureMaximum2]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=11

[mForecastTemperatureMaximumSymbol2]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=12

[mForecastTemperatureMinimum2]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=13

[mForecastTemperatureMinimumSymbol2]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=14

[mForecastPrecipitationPercent2]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=15

[mForecastPrecipitationPercentSymbol2]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=16

[mForecastWeekDay3]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=17

[mForecastConditionIcon3]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=18

[mForecastDate3]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=19

[mForecastConditionText3]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=20
DecodeCharacterReference=1

[mForecastTemperatureMaximum3]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=21

[mForecastTemperatureMaximumSymbol3]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=22

[mForecastTemperatureMinimum3]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=23

[mForecastTemperatureMinimumSymbol3]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=24

[mForecastPrecipitationPercent3]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=25

[mForecastPrecipitationPercentSymbol3]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=26

[mForecastWeekDay4]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=27

[mForecastConditionIcon4]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=28

[mForecastDate4]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=29

[mForecastConditionText4]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=30
DecodeCharacterReference=1

[mForecastTemperatureMaximum4]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=31

[mForecastTemperatureMaximumSymbol4]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=32

[mForecastTemperatureMinimum4]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=33

[mForecastTemperatureMinimumSymbol4]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=34

[mForecastPrecipitationPercent4]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=35

[mForecastPrecipitationPercentSymbol4]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=36

[mForecastWeekDay5]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=37

[mForecastConditionIcon5]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=38

[mForecastDate5]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=39

[mForecastConditionText5]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=40
DecodeCharacterReference=1

[mForecastTemperatureMaximum5]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=41

[mForecastTemperatureMaximumSymbol5]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=42

[mForecastTemperatureMinimum5]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=43

[mForecastTemperatureMinimumSymbol5]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=44

[mForecastPrecipitationPercent5]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=45

[mForecastPrecipitationPercentSymbol5]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=46

[mForecastWeekDay6]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=47

[mForecastConditionIcon6]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=48

[mForecastDate6]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=49

[mForecastConditionText6]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=50
DecodeCharacterReference=1

[mForecastTemperatureMaximum6]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=51

[mForecastTemperatureMaximumSymbol6]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=52

[mForecastTemperatureMinimum6]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=53

[mForecastTemperatureMinimumSymbol6]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=54

[mForecastPrecipitationPercent6]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=55

[mForecastPrecipitationPercentSymbol6]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=56

[mForecastWeekDay7]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=57

[mForecastConditionIcon7]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=58

[mForecastDate7]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=59

[mForecastConditionText7]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=60
DecodeCharacterReference=1

[mForecastTemperatureMaximum7]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=61

[mForecastTemperatureMaximumSymbol7]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=62

[mForecastTemperatureMinimum7]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=63

[mForecastTemperatureMinimumSymbol7]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=64

[mForecastPrecipitationPercent7]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=65

[mForecastPrecipitationPercentSymbol7]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=66

[mForecastWeekDay8]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=67

[mForecastConditionIcon8]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=68

[mForecastDate8]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=69

[mForecastConditionText8]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=70
DecodeCharacterReference=1

[mForecastTemperatureMaximum8]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=71

[mForecastTemperatureMaximumSymbol8]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=72

[mForecastTemperatureMinimum8]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=73

[mForecastTemperatureMinimumSymbol8]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=74

[mForecastPrecipitationPercent8]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=75

[mForecastPrecipitationPercentSymbol8]
Measure=WebParser
Group=WeatherForecasts
Url=[mForecast]
StringIndex=76

;===============================SUN MEASURES==================================

[mSUN]
Measure=WebParser
Url=#URL#
RegExp=#SUN#
UpdateRate=#WeatherUpdateRate#
LogSubstringErrors=0
FinishAction=[!Log "Retrieved sunrise and sunset."][!UpdateMeasureGroup Sun][!UpdateMeterGroup WeatherMeters][!UpdateMeter *]
OnConnectErrorAction=[!HideMeterGroup WeatherMeters][!ShowMeter RetrievingWeather][!SetOption RefreshButton MouseLeaveAction "[!HideMeter RefreshButtonHoverEdge][!ShowMeter RefreshButtonEdge][!ShowMeter RefreshButtonCenter]"][!UpdateMeter RefreshButton][!ShowMeterGroup RefreshOverlay][!HideMeter RefreshButtonHoverEdge][!Log "Can not retrieved sunrise and sunset. No Connection." Error]
OnRegExpErrorAction=[!HideMeterGroup WeatherMeters][!ShowMeter RetrievingWeather][!SetOption RefreshButton MouseLeaveAction "[!HideMeter RefreshButtonHoverEdge][!ShowMeter RefreshButtonEdge][!ShowMeter RefreshButtonCenter]"][!UpdateMeter RefreshButton][!ShowMeterGroup RefreshOverlay][!HideMeter RefreshButtonHoverEdge][!Log "Can not read sunrise and sunset." Error]
DynamicVariables=1

[mSUNRISEText]
Measure=WebParser
Group=Sun
Url=[mSUN]
StringIndex=1
Substitute="sunrise":"☀↑"

[mSUNRISE]
Measure=WebParser
Group=Sun
Url=[mSUN]
StringIndex=2

[mSUNSETText]
Measure=WebParser
Group=Sun
Url=[mSUN]
StringIndex=3
Substitute="sunset":"☀↓"

[mSUNSET]
Measure=WebParser
Group=Sun
Url=[mSUN]
StringIndex=4

;===============================DETAIL MEASURES==================================

[mDetails]
Measure=WebParser
Url=#URL3#
RegExp=#Details#
UpdateRate=#WeatherUpdateRate#
LogSubstringErrors=0
FinishAction=[!Log "Retrieved details."][!SetOption RefreshButton MouseLeaveAction "[]"][!UpdateMeter RefreshButton][!HideMeterGroup RefreshOverlay][!UpdateMeasureGroup WeatherDetails][!ShowMeterGroup WeatherMeters][!UpdateMeterGroup WeatherMeters][!HideMeter RetrievingWeather][!UpdateMeter *][!Redraw]
OnConnectErrorAction=[!HideMeterGroup WeatherMeters][!ShowMeter RetrievingWeather][!SetOption RefreshButton MouseLeaveAction "[!HideMeter RefreshButtonHoverEdge][!ShowMeter RefreshButtonEdge][!ShowMeter RefreshButtonCenter]"][!UpdateMeter RefreshButton][!ShowMeterGroup RefreshOverlay][!HideMeter RefreshButtonHoverEdge][!Log "Can not retrieved details. No Connection." Error]
OnRegExpErrorAction=[!HideMeterGroup WeatherMeters][!ShowMeter RetrievingWeather][!SetOption RefreshButton MouseLeaveAction "[!HideMeter RefreshButtonHoverEdge][!ShowMeter RefreshButtonEdge][!ShowMeter RefreshButtonCenter]"][!UpdateMeter RefreshButton][!ShowMeterGroup RefreshOverlay][!HideMeter RefreshButtonHoverEdge][!Log "Can not read details." Error]
DynamicVariables=1

[mDetails1]
Measure=WebParser
Group=WeatherDetails
Url=[mDetails]
StringIndex=1
DecodeCharacterReference=1

[mDetails2]
Measure=WebParser
Group=WeatherDetails
Url=[mDetails]
StringIndex=2
DecodeCharacterReference=1

[mDetails3]
Measure=WebParser
Group=WeatherDetails
Url=[mDetails]
StringIndex=3
DecodeCharacterReference=1

[mDetails4]
Measure=WebParser
Group=WeatherDetails
Url=[mDetails]
StringIndex=4
DecodeCharacterReference=1

[mDetails5]
Measure=WebParser
Group=WeatherDetails
Url=[mDetails]
StringIndex=5
DecodeCharacterReference=1

[mDetails6]
Measure=WebParser
Group=WeatherDetails
Url=[mDetails]
StringIndex=6
DecodeCharacterReference=1

[mDetails7]
Measure=WebParser
Group=WeatherDetails
Url=[mDetails]
StringIndex=7
DecodeCharacterReference=1

[mDetails8]
Measure=WebParser
Group=WeatherDetails
Url=[mDetails]
StringIndex=8
DecodeCharacterReference=1

; ;===============================SEVERE ALERT MEASURES==================================

; [mSevereAlert]
; Measure=WebParser
; Url=#URL#
; RegExp=#SevereAlert#
; UpdateRate=#WeatherUpdateRate#
; LogSubstringErrors=0
; IfMatch=localalerts
; IfMatchAction=[!EnableMeasure "mALERT"][!EnableMeasure "mPriorityAlert"][!CommandMeasure mALERT "Update"][!CommandMeasure mPriorityAlert "Update"]
; IfNotMatchAction=[!DisableMeasure "mALERT"][!DisableMeasure "mPriorityAlert"][!HideMeterGroup "Alerts"]

; [mPriorityAlert]
; Measure=WebParser
; Url=#URL#
; RegExp=#PriorityAlert#
; UpdateRate=#WeatherUpdateRate#
; LogSubstringErrors=0
; Disabled=1

; [mAlertPLevel]
; Measure=WebParser
; Url=[mPriorityAlert]
; StringIndex=1

; [mALERTP]
; Measure=WebParser
; Url=[mPriorityAlert]
; StringIndex=2
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; [mAlertPTime]
; Measure=WebParser
; Url=[mPriorityAlert]
; StringIndex=3
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; ;===============================ALERT MEASURES==================================

; [mALERT]
; Measure=WebParser
; Url=#URL#
; RegExp=#ALERT#
; UpdateRate=#WeatherUpdateRate#
; LogSubstringErrors=0
; IfMatch=priority bg-alert-1
; IfMatchAction=[!ShowMeter "MeterAlertIcon1"]
; IfNotMatchAction=[!HideMeter "MeterAlertIcon1"]                           
; IfMatch2=priority bg-alert-2
; IfMatchAction2=[!ShowMeter "MeterAlertIcon2"]
; IfNotMatchAction2=[!HideMeter "MeterAlertIcon2"]
; IfMatch3=priority bg-alert-3
; IfMatchAction3=[!ShowMeter "MeterAlertIcon3"]
; IfNotMatchAction3=[!HideMeter "MeterAlertIcon3"]
; IfMatch4=priority bg-alert-4
; IfMatchAction4=[!ShowMeter "MeterAlertIcon4"]
; IfNotMatchAction4=[!HideMeter "MeterAlertIcon4"]
; Disabled=1

; [mAlert1Level]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=1

; [mALERT1]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=2
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1
; IfMatch=^$
; IfMatchAction=[!SetVariable 1st "0"]
; IfNotMatchAction=[!SetVariable 1st "1"]

; [mAlert1Time]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=3
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; [mAlert2Level]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=4

; [mALERT2]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=5
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1
; IfMatch=^$
; IfMatchAction=[!SetVariable 2nd "0"]
; IfNotMatchAction=[!SetVariable 2nd "1"]

; [mAlert2Time]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=6
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; [mAlert3Level]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=7

; [mALERT3]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=8
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1
; IfMatch=^$
; IfMatchAction=[!SetVariable 3rd "0"]
; IfNotMatchAction=[!SetVariable 3rd "1"]

; [mAlert3Time]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=9
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; [mAlert4Level]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=10

; [mALERT4]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=11
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1
; IfMatch=^$
; IfMatchAction=[!SetVariable 4th "0"]
; IfNotMatchAction=[!SetVariable 4th "1"]

; [mAlert4Time]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=12
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; [mAlert5Level]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=13

; [mALERT5]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=14
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1
; IfMatch=^$
; IfMatchAction=[!SetVariable 5th "0"]
; IfNotMatchAction=[!SetVariable 5th "1"]

; [mAlert5Time]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=15
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; [mAlert6Level]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=16

; [mALERT6]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=17
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1
; IfMatch=^$
; IfMatchAction=[!SetVariable 6th "0"]
; IfNotMatchAction=[!SetVariable 6th "1"]

; [mAlert6Time]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=18
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; [mAlert7Level]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=19

; [mALERT7]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=20
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1
; IfMatch=^$
; IfMatchAction=[!SetVariable 7th "0"]
; IfNotMatchAction=[!SetVariable 7th "1"]

; [mAlert7Time]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=21
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; [mAlert8Level]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=22

; [mALERT8]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=23
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1
; IfMatch=^$
; IfMatchAction=[!SetVariable 8th "0"]
; IfNotMatchAction=[!SetVariable 8th "1"]

; [mAlert8Time]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=24
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; [mAlert9Level]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=25

; [mALERT9]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=26
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1
; IfMatch=^$
; IfMatchAction=[!SetVariable 9th "0"]
; IfNotMatchAction=[!SetVariable 9th "1"]

; [mAlert9Time]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=27
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; [mAlert10Level]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=28

; [mALERT10]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=29
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1
; IfMatch=^$
; IfMatchAction=[!SetVariable 10th "0"]
; IfNotMatchAction=[!SetVariable 10th "1"]

; [mAlert10Time]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=30
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; [mAlert11Level]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=31

; [mALERT11]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=32
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1
; IfMatch=^$
; IfMatchAction=[!SetVariable 11th "0"]
; IfNotMatchAction=[!SetVariable 11th "1"]

; [mAlert11Time]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=33
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; [mAlert12Level]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=34

; [mALERT12]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=35
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1
; IfMatch=^$
; IfMatchAction=[!SetVariable 12th "0"]
; IfNotMatchAction=[!SetVariable 12th "1"]

; [mAlert12Time]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=36
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; [mAlert13Level]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=37

; [mALERT13]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=38
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1
; IfMatch=^$
; IfMatchAction=[!SetVariable 13th "0"]
; IfNotMatchAction=[!SetVariable 13th "1"]

; [mAlert13Time]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=39
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; [mAlert14Level]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=40

; [mALERT14]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=41
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1
; IfMatch=^$
; IfMatchAction=[!SetVariable 14th "0"]
; IfNotMatchAction=[!SetVariable 14th "1"]

; [mAlert14Time]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=42
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; [mAlert15Level]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=43

; [mALERT15]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=44
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1
; IfMatch=^$
; IfMatchAction=[!SetVariable 15th "0"]
; IfNotMatchAction=[!SetVariable 15th "1"]

; [mAlert15Time]
; Measure=WebParser
; Url=[mALERT]
; StringIndex=45
; DecodeCharacterReference=1
; RegExpSubstitute=1
; Substitute="^(?!\s*$)(.*)":"\1#CRLF#"
; DynamicVariables=1

; [mNum]
; Measure=Calc
; Formula=( #1st# + #2nd# + #3rd# + #4th# + #5th# + #6th# +#7th# + #8th# + #9th# + #10th# + #11th# + #12th# + #13th# + #14th# + #15th# )
; IfCondition=(#CURRENTSECTION#=1)
; IfTrueAction=[!SetOptionGroup Alerts ToolTipHidden "0"][!SetOptionGroup Alerts ToolTipText "[*mAlertPLevel*]  [*mALERTP*]    [*mAlertPTime*]#CRLF#Click for more information."][!UpdateMeterGroup "Alerts"]
; IfCondition2=(#CURRENTSECTION#=2)
; IfTrueAction2=[!SetOptionGroup Alerts ToolTipHidden "0"][!SetOptionGroup Alerts ToolTipText "[*mAlertPLevel*]  [*mALERTP*]    [*mAlertPTime*][*mAlert1Level*]  [*mALERT1*]    [*mAlert1Time*]#CRLF#Click for more information."][!UpdateMeterGroup "Alerts"]
; IfCondition3=(#CURRENTSECTION#=3)
; IfTrueAction3=[!SetOptionGroup Alerts ToolTipHidden "0"][!SetOptionGroup Alerts ToolTipText "[*mAlertPLevel*]  [*mALERTP*]    [*mAlertPTime*][*mAlert1Level*]  [*mALERT1*]    [*mAlert1Time*][*mAlert2Level*]  [*mALERT2*]    [*mAlert2Time*]#CRLF#Click for more information."][!UpdateMeterGroup "Alerts"]
; IfCondition4=(#CURRENTSECTION#=4)
; IfTrueAction4=[!SetOptionGroup Alerts ToolTipHidden "0"][!SetOptionGroup Alerts ToolTipText "[*mAlertPLevel*]  [*mALERTP*]    [*mAlertPTime*][*mAlert1Level*]  [*mALERT1*]    [*mAlert1Time*][*mAlert2Level*]  [*mALERT2*]    [*mAlert2Time*][*mAlert3Level*]  [*mALERT3*]    [*mAlert3Time*]#CRLF#Click for more information."][!UpdateMeterGroup "Alerts"]
; IfCondition5=(#CURRENTSECTION#=5)
; IfTrueAction5=[!SetOptionGroup Alerts ToolTipHidden "0"][!SetOptionGroup Alerts ToolTipText "[*mAlertPLevel*]  [*mALERTP*]    [*mAlertPTime*][*mAlert1Level*]  [*mALERT1*]    [*mAlert1Time*][*mAlert2Level*]  [*mALERT2*]    [*mAlert2Time*][*mAlert3Level*]  [*mALERT3*]    [*mAlert3Time*][*mAlert4Level*]  [*mALERT4*]    [*mAlert4Time*]#CRLF#Click for more information."][!UpdateMeterGroup "Alerts"]
; IfCondition6=(#CURRENTSECTION#=6)
; IfTrueAction6=[!SetOptionGroup Alerts ToolTipHidden "0"][!SetOptionGroup Alerts ToolTipText "[*mAlertPLevel*]  [*mALERTP*]    [*mAlertPTime*][*mAlert1Level*]  [*mALERT1*]    [*mAlert1Time*][*mAlert2Level*]  [*mALERT2*]    [*mAlert2Time*][*mAlert3Level*]  [*mALERT3*]    [*mAlert3Time*][*mAlert4Level*]  [*mALERT4*]    [*mAlert4Time*][*mAlert5Level*]  [*mALERT5*]    [*mAlert5Time*]#CRLF#Click for more information."][!UpdateMeterGroup "Alerts"]
; IfCondition7=(#CURRENTSECTION#=7)
; IfTrueAction7=[!SetOptionGroup Alerts ToolTipHidden "0"][!SetOptionGroup Alerts ToolTipText "[*mAlertPLevel*]  [*mALERTP*]    [*mAlertPTime*][*mAlert1Level*]  [*mALERT1*]    [*mAlert1Time*][*mAlert2Level*]  [*mALERT2*]    [*mAlert2Time*][*mAlert3Level*]  [*mALERT3*]    [*mAlert3Time*][*mAlert4Level*]  [*mALERT4*]    [*mAlert4Time*][*mAlert5Level*]  [*mALERT5*]    [*mAlert5Time*][*mAlert6Level*]  [*mALERT6*]    [*mAlert6Time*]#CRLF#Click for more information."][!UpdateMeterGroup "Alerts"]
; IfCondition8=(#CURRENTSECTION#=8)
; IfTrueAction8=[!SetOptionGroup Alerts ToolTipHidden "0"][!SetOptionGroup Alerts ToolTipText "[*mAlertPLevel*]  [*mALERTP*]    [*mAlertPTime*][*mAlert1Level*]  [*mALERT1*]    [*mAlert1Time*][*mAlert2Level*]  [*mALERT2*]    [*mAlert2Time*][*mAlert3Level*]  [*mALERT3*]    [*mAlert3Time*][*mAlert4Level*]  [*mALERT4*]    [*mAlert4Time*][*mAlert5Level*]  [*mALERT5*]    [*mAlert5Time*][*mAlert6Level*]  [*mALERT6*]    [*mAlert6Time*][*mAlert7Level*]  [*mALERT7*]    [*mAlert7Time*]#CRLF#Click for more information."][!UpdateMeterGroup "Alerts"]
; IfCondition9=(#CURRENTSECTION#=9)
; IfTrueAction9=[!SetOptionGroup Alerts ToolTipHidden "0"][!SetOptionGroup Alerts ToolTipText "[*mAlertPLevel*]  [*mALERTP*]    [*mAlertPTime*][*mAlert1Level*]  [*mALERT1*]    [*mAlert1Time*][*mAlert2Level*]  [*mALERT2*]    [*mAlert2Time*][*mAlert3Level*]  [*mALERT3*]    [*mAlert3Time*][*mAlert4Level*]  [*mALERT4*]    [*mAlert4Time*][*mAlert5Level*]  [*mALERT5*]    [*mAlert5Time*][*mAlert6Level*]  [*mALERT6*]    [*mAlert6Time*][*mAlert7Level*]  [*mALERT7*]    [*mAlert7Time*][*mAlert8Level*]  [*mALERT8*]    [*mAlert8Time*]#CRLF#Click for more information."][!UpdateMeterGroup "Alerts"]
; IfCondition10=(#CURRENTSECTION#=10)
; IfTrueAction10=[!SetOptionGroup Alerts ToolTipHidden "0"][!SetOptionGroup Alerts ToolTipText "[*mAlertPLevel*]  [*mALERTP*]    [*mAlertPTime*][*mAlert1Level*]  [*mALERT1*]    [*mAlert1Time*][*mAlert2Level*]  [*mALERT2*]    [*mAlert2Time*][*mAlert3Level*]  [*mALERT3*]    [*mAlert3Time*][*mAlert4Level*]  [*mALERT4*]    [*mAlert4Time*][*mAlert5Level*]  [*mALERT5*]    [*mAlert5Time*][*mAlert6Level*]  [*mALERT6*]    [*mAlert6Time*][*mAlert7Level*]  [*mALERT7*]    [*mAlert7Time*][*mAlert8Level*]  [*mALERT8*]    [*mAlert8Time*][*mAlert9Level*]  [*mALERT9*]    [*mAlert9Time*]#CRLF#Click for more information."][!UpdateMeterGroup "Alerts"]
; IfCondition11=(#CURRENTSECTION#=11)
; IfTrueAction11=[!SetOptionGroup Alerts ToolTipHidden "0"][!SetOptionGroup Alerts ToolTipText "[*mAlertPLevel*]  [*mALERTP*]    [*mAlertPTime*][*mAlert1Level*]  [*mALERT1*]    [*mAlert1Time*][*mAlert2Level*]  [*mALERT2*]    [*mAlert2Time*][*mAlert3Level*]  [*mALERT3*]    [*mAlert3Time*][*mAlert4Level*]  [*mALERT4*]    [*mAlert4Time*][*mAlert5Level*]  [*mALERT5*]    [*mAlert5Time*][*mAlert6Level*]  [*mALERT6*]    [*mAlert6Time*][*mAlert7Level*]  [*mALERT7*]    [*mAlert7Time*][*mAlert8Level*]  [*mALERT8*]    [*mAlert8Time*][*mAlert9Level*]  [*mALERT9*]    [*mAlert9Time*][*mAlert10Level*]  [*mALERT10*]    [*mAlert10Time*]#CRLF#Click for more information."][!UpdateMeterGroup "Alerts"]
; IfCondition12=(#CURRENTSECTION#=12)
; IfTrueAction12=[!SetOptionGroup Alerts ToolTipHidden "0"][!SetOptionGroup Alerts ToolTipText "[*mAlertPLevel*]  [*mALERTP*]    [*mAlertPTime*][*mAlert1Level*]  [*mALERT1*]    [*mAlert1Time*][*mAlert2Level*]  [*mALERT2*]    [*mAlert2Time*][*mAlert3Level*]  [*mALERT3*]    [*mAlert3Time*][*mAlert4Level*]  [*mALERT4*]    [*mAlert4Time*][*mAlert5Level*]  [*mALERT5*]    [*mAlert5Time*][*mAlert6Level*]  [*mALERT6*]    [*mAlert6Time*][*mAlert7Level*]  [*mALERT7*]    [*mAlert7Time*][*mAlert8Level*]  [*mALERT8*]    [*mAlert8Time*][*mAlert9Level*]  [*mALERT9*]    [*mAlert9Time*][*mAlert10Level*]  [*mALERT10*]    [*mAlert10Time*][*mAlert11Level*]  [*mALERT11*]    [*mAlert11Time*]#CRLF#Click for more information."][!UpdateMeterGroup "Alerts"]
; IfCondition13=(#CURRENTSECTION#=13)
; IfTrueAction13=[!SetOptionGroup Alerts ToolTipHidden "0"][!SetOptionGroup Alerts ToolTipText "[*mAlertPLevel*]  [*mALERTP*]    [*mAlertPTime*][*mAlert1Level*]  [*mALERT1*]    [*mAlert1Time*][*mAlert2Level*]  [*mALERT2*]    [*mAlert2Time*][*mAlert3Level*]  [*mALERT3*]    [*mAlert3Time*][*mAlert4Level*]  [*mALERT4*]    [*mAlert4Time*][*mAlert5Level*]  [*mALERT5*]    [*mAlert5Time*][*mAlert6Level*]  [*mALERT6*]    [*mAlert6Time*][*mAlert7Level*]  [*mALERT7*]    [*mAlert7Time*][*mAlert8Level*]  [*mALERT8*]    [*mAlert8Time*][*mAlert9Level*]  [*mALERT9*]    [*mAlert9Time*][*mAlert10Level*]  [*mALERT10*]    [*mAlert10Time*][*mAlert11Level*]  [*mALERT11*]    [*mAlert11Time*][*mAlert12Level*]  [*mALERT12*]   [*mAlert12Time*]#CRLF#Click for more information."][!UpdateMeterGroup "Alerts"]
; IfCondition14=(#CURRENTSECTION#=14)
; IfTrueAction14=[!SetOptionGroup Alerts ToolTipHidden "0"][!SetOptionGroup Alerts ToolTipText "[*mAlertPLevel*]  [*mALERTP*]    [*mAlertPTime*][*mAlert1Level*]  [*mALERT1*]    [*mAlert1Time*][*mAlert2Level*]  [*mALERT2*]    [*mAlert2Time*][*mAlert3Level*]  [*mALERT3*]    [*mAlert3Time*][*mAlert4Level*]  [*mALERT4*]    [*mAlert4Time*][*mAlert5Level*]  [*mALERT5*]    [*mAlert5Time*][*mAlert6Level*]  [*mALERT6*]    [*mAlert6Time*][*mAlert7Level*]  [*mALERT7*]    [*mAlert7Time*][*mAlert8Level*]  [*mALERT8*]    [*mAlert8Time*][*mAlert9Level*]  [*mALERT9*]    [*mAlert9Time*][*mAlert10Level*]  [*mALERT10*]    [*mAlert10Time*][*mAlert11Level*]  [*mALERT11*]    [*mAlert11Time*][*mAlert12Level*]  [*mALERT12*]   [*mAlert12Time*][*mAlert13Level*]  [*mALERT13*]    [*mAlert13Time*]#CRLF#Click for more information."][!UpdateMeterGroup "Alerts"]
; IfCondition15=(#CURRENTSECTION#=15)
; IfTrueAction15=[!SetOptionGroup Alerts ToolTipHidden "0"][!SetOptionGroup Alerts ToolTipText "[*mAlertPLevel*]  [*mALERTP*]    [*mAlertPTime*][*mAlert1Level*]  [*mALERT1*]    [*mAlert1Time*][*mAlert2Level*]  [*mALERT2*]    [*mAlert2Time*][*mAlert3Level*]  [*mALERT3*]    [*mAlert3Time*][*mAlert4Level*]  [*mALERT4*]    [*mAlert4Time*][*mAlert5Level*]  [*mALERT5*]    [*mAlert5Time*][*mAlert6Level*]  [*mALERT6*]    [*mAlert6Time*][*mAlert7Level*]  [*mALERT7*]    [*mAlert7Time*][*mAlert8Level*]  [*mALERT8*]    [*mAlert8Time*][*mAlert9Level*]  [*mALERT9*]    [*mAlert9Time*][*mAlert10Level*]  [*mALERT10*]    [*mAlert10Time*][*mAlert11Level*]  [*mALERT11*]    [*mAlert11Time*][*mAlert12Level*]  [*mALERT12*]   [*mAlert12Time*][*mAlert13Level*]  [*mALERT13*]    [*mAlert13Time*][*mAlert14Level*]  [*mALERT14*]    [*mAlert14Time*]#CRLF#Click for more information."][!UpdateMeterGroup "Alerts"]
; DynamicVariables=1

; ;===============================HIDE/SHOW DAYS MEASURES==================================

; [mShowDays]
; Measure=Calc
; Formula=#Days#
; IfCondition=(#CURRENTSECTION#=0)
; IfTrueAction=[!HideMeterGroup "DAY2"][!HideMeterGroup "DAY3"][!HideMeterGroup "DAY4"][!HideMeterGroup "DAY5"][!HideMeterGroup "DAY6"][!HideMeterGroup "DAY7"][!HideMeterGroup "DAY8"][!Redraw]
; IfCondition2=(#CURRENTSECTION#=1)
; IfTrueAction2=[!ShowMeterGroup "DAY2"][!HideMeterGroup "DAY3"][!HideMeterGroup "DAY4"][!HideMeterGroup "DAY5"][!HideMeterGroup "DAY6"][!HideMeterGroup "DAY7"][!HideMeterGroup "DAY8"][!Redraw]
; IfCondition3=(#CURRENTSECTION#=2)
; IfTrueAction3=[!ShowMeterGroup "DAY2"][!ShowMeterGroup "DAY3"][!HideMeterGroup "DAY4"][!HideMeterGroup "DAY5"][!HideMeterGroup "DAY6"][!HideMeterGroup "DAY7"][!HideMeterGroup "DAY8"][!Redraw]
; IfCondition4=(#CURRENTSECTION#=3)
; IfTrueAction4=[!ShowMeterGroup "DAY2"][!ShowMeterGroup "DAY3"][!ShowMeterGroup "DAY4"][!HideMeterGroup "DAY5"][!HideMeterGroup "DAY6"][!HideMeterGroup "DAY7"][!HideMeterGroup "DAY8"][!Redraw]
; IfCondition5=(#CURRENTSECTION#=4)
; IfTrueAction5=[!ShowMeterGroup "DAY2"][!ShowMeterGroup "DAY3"][!ShowMeterGroup "DAY4"][!ShowMeterGroup "DAY5"][!HideMeterGroup "DAY6"][!HideMeterGroup "DAY7"][!HideMeterGroup "DAY8"][!Redraw]
; IfCondition6=(#CURRENTSECTION#=5)
; IfTrueAction6=[!ShowMeterGroup "DAY2"][!ShowMeterGroup "DAY3"][!ShowMeterGroup "DAY4"][!ShowMeterGroup "DAY5"][!ShowMeterGroup "DAY6"][!HideMeterGroup "DAY7"][!HideMeterGroup "DAY8"][!Redraw]
; IfCondition7=(#CURRENTSECTION#=6)
; IfTrueAction7=[!ShowMeterGroup "DAY2"][!ShowMeterGroup "DAY3"][!ShowMeterGroup "DAY4"][!ShowMeterGroup "DAY5"][!ShowMeterGroup "DAY6"][!ShowMeterGroup "DAY7"][!HideMeterGroup "DAY8"][!Redraw]
; IfCondition8=(#CURRENTSECTION#=7)
; IfTrueAction8=[!ShowMeterGroup "DAY2"][!ShowMeterGroup "DAY3"][!ShowMeterGroup "DAY4"][!ShowMeterGroup "DAY5"][!ShowMeterGroup "DAY6"][!ShowMeterGroup "DAY7"][!ShowMeterGroup "DAY8"][!Redraw]
; DynamicVariables=1


