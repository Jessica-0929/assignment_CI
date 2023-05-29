#include "../include/can_message/min_signals.h"
#include <sstream>

CAN_min_signals::CAN_min_signals() {
	m_startMsgId = 100;
	m_temperatureGetMsgId = m_startMsgId + 2; 
	m_temperatureSetMsgId = m_startMsgId + 2 + 1;
	m_humidityGetMsgId = m_startMsgId + 4; 
	m_humiditySetMsgId = m_startMsgId + 4 + 1;
	m_front_sensor_statusGetMsgId = m_startMsgId + 6; 
	m_front_sensor_statusSetMsgId = m_startMsgId + 6 + 1;
	m_flow_rateGetMsgId = m_startMsgId + 8; 
	m_flow_rateSetMsgId = m_startMsgId + 8 + 1;
	m_flow_meter_sensor_statusGetMsgId = m_startMsgId + 10; 
	m_flow_meter_sensor_statusSetMsgId = m_startMsgId + 10 + 1;
	m_light_intensityGetMsgId = m_startMsgId + 12; 
	m_light_intensitySetMsgId = m_startMsgId + 12 + 1;
	m_light_intensity_sensor_statusGetMsgId = m_startMsgId + 14; 
	m_light_intensity_sensor_statusSetMsgId = m_startMsgId + 14 + 1;
	m_water_levelGetMsgId = m_startMsgId + 16; 
	m_water_levelSetMsgId = m_startMsgId + 16 + 1;
	m_water_level_sensor_statusGetMsgId = m_startMsgId + 18; 
	m_water_level_sensor_statusSetMsgId = m_startMsgId + 18 + 1;
	m_soil_moistureGetMsgId = m_startMsgId + 20; 
	m_soil_moistureSetMsgId = m_startMsgId + 20 + 1;
	m_soil_moisture_sensor_statusGetMsgId = m_startMsgId + 22; 
	m_soil_moisture_sensor_statusSetMsgId = m_startMsgId + 22 + 1;
	m_stop_signal_lightGetMsgId = m_startMsgId + 24; 
	m_stop_signal_lightSetMsgId = m_startMsgId + 24 + 1;
};
std::string CAN_min_signals::get_temperature() { 
	std::stringstream sstream; 
	sstream << "{\"ID\": " << + m_temperatureGetMsgId
			<< ", \"length\":0 "
			<< ", \"value\": \"\" }";
	return sstream.str();
}
std::string CAN_min_signals::set_temperature(float newValue) {
	std::stringstream sstream;
	sstream << "{\"ID\": " << + m_temperatureSetMsgId
			<< ", \"length\":10 "
			<< ", \"value\":\""
			<< + newValue
			<< "\"}";
	return sstream.str();
}
std::string CAN_min_signals::get_humidity() { 
	std::stringstream sstream; 
	sstream << "{\"ID\": " << + m_humidityGetMsgId
			<< ", \"length\":0 "
			<< ", \"value\": \"\" }";
	return sstream.str();
}
std::string CAN_min_signals::set_humidity(uint8_t newValue) {
	std::stringstream sstream;
	sstream << "{\"ID\": " << + m_humiditySetMsgId
			<< ", \"length\":7 "
			<< ", \"value\":\""
			<< + newValue
			<< "\"}";
	return sstream.str();
}
std::string CAN_min_signals::get_front_sensor_status() { 
	std::stringstream sstream; 
	sstream << "{\"ID\": " << + m_front_sensor_statusGetMsgId
			<< ", \"length\":0 "
			<< ", \"value\": \"\" }";
	return sstream.str();
}
std::string CAN_min_signals::set_front_sensor_status(bool newValue) {
	std::stringstream sstream;
	sstream << "{\"ID\": " << + m_front_sensor_statusSetMsgId
			<< ", \"length\":1 "
			<< ", \"value\":\""
			<< + newValue
			<< "\"}";
	return sstream.str();
}
std::string CAN_min_signals::get_flow_rate() { 
	std::stringstream sstream; 
	sstream << "{\"ID\": " << + m_flow_rateGetMsgId
			<< ", \"length\":0 "
			<< ", \"value\": \"\" }";
	return sstream.str();
}
std::string CAN_min_signals::set_flow_rate(uint16_t newValue) {
	std::stringstream sstream;
	sstream << "{\"ID\": " << + m_flow_rateSetMsgId
			<< ", \"length\":9 "
			<< ", \"value\":\""
			<< + newValue
			<< "\"}";
	return sstream.str();
}
std::string CAN_min_signals::get_flow_meter_sensor_status() { 
	std::stringstream sstream; 
	sstream << "{\"ID\": " << + m_flow_meter_sensor_statusGetMsgId
			<< ", \"length\":0 "
			<< ", \"value\": \"\" }";
	return sstream.str();
}
std::string CAN_min_signals::set_flow_meter_sensor_status(uint8_t newValue) {
	std::stringstream sstream;
	sstream << "{\"ID\": " << + m_flow_meter_sensor_statusSetMsgId
			<< ", \"length\":2 "
			<< ", \"value\":\""
			<< + newValue
			<< "\"}";
	return sstream.str();
}
std::string CAN_min_signals::get_light_intensity() { 
	std::stringstream sstream; 
	sstream << "{\"ID\": " << + m_light_intensityGetMsgId
			<< ", \"length\":0 "
			<< ", \"value\": \"\" }";
	return sstream.str();
}
std::string CAN_min_signals::set_light_intensity(uint8_t newValue) {
	std::stringstream sstream;
	sstream << "{\"ID\": " << + m_light_intensitySetMsgId
			<< ", \"length\":7 "
			<< ", \"value\":\""
			<< + newValue
			<< "\"}";
	return sstream.str();
}
std::string CAN_min_signals::get_light_intensity_sensor_status() { 
	std::stringstream sstream; 
	sstream << "{\"ID\": " << + m_light_intensity_sensor_statusGetMsgId
			<< ", \"length\":0 "
			<< ", \"value\": \"\" }";
	return sstream.str();
}
std::string CAN_min_signals::set_light_intensity_sensor_status(uint8_t newValue) {
	std::stringstream sstream;
	sstream << "{\"ID\": " << + m_light_intensity_sensor_statusSetMsgId
			<< ", \"length\":2 "
			<< ", \"value\":\""
			<< + newValue
			<< "\"}";
	return sstream.str();
}
std::string CAN_min_signals::get_water_level() { 
	std::stringstream sstream; 
	sstream << "{\"ID\": " << + m_water_levelGetMsgId
			<< ", \"length\":0 "
			<< ", \"value\": \"\" }";
	return sstream.str();
}
std::string CAN_min_signals::set_water_level(uint8_t newValue) {
	std::stringstream sstream;
	sstream << "{\"ID\": " << + m_water_levelSetMsgId
			<< ", \"length\":7 "
			<< ", \"value\":\""
			<< + newValue
			<< "\"}";
	return sstream.str();
}
std::string CAN_min_signals::get_water_level_sensor_status() { 
	std::stringstream sstream; 
	sstream << "{\"ID\": " << + m_water_level_sensor_statusGetMsgId
			<< ", \"length\":0 "
			<< ", \"value\": \"\" }";
	return sstream.str();
}
std::string CAN_min_signals::set_water_level_sensor_status(uint8_t newValue) {
	std::stringstream sstream;
	sstream << "{\"ID\": " << + m_water_level_sensor_statusSetMsgId
			<< ", \"length\":2 "
			<< ", \"value\":\""
			<< + newValue
			<< "\"}";
	return sstream.str();
}
std::string CAN_min_signals::get_soil_moisture() { 
	std::stringstream sstream; 
	sstream << "{\"ID\": " << + m_soil_moistureGetMsgId
			<< ", \"length\":0 "
			<< ", \"value\": \"\" }";
	return sstream.str();
}
std::string CAN_min_signals::set_soil_moisture(uint8_t newValue) {
	std::stringstream sstream;
	sstream << "{\"ID\": " << + m_soil_moistureSetMsgId
			<< ", \"length\":7 "
			<< ", \"value\":\""
			<< + newValue
			<< "\"}";
	return sstream.str();
}
std::string CAN_min_signals::get_soil_moisture_sensor_status() { 
	std::stringstream sstream; 
	sstream << "{\"ID\": " << + m_soil_moisture_sensor_statusGetMsgId
			<< ", \"length\":0 "
			<< ", \"value\": \"\" }";
	return sstream.str();
}
std::string CAN_min_signals::set_soil_moisture_sensor_status(uint8_t newValue) {
	std::stringstream sstream;
	sstream << "{\"ID\": " << + m_soil_moisture_sensor_statusSetMsgId
			<< ", \"length\":2 "
			<< ", \"value\":\""
			<< + newValue
			<< "\"}";
	return sstream.str();
}
std::string CAN_min_signals::get_stop_signal_light() { 
	std::stringstream sstream; 
	sstream << "{\"ID\": " << + m_stop_signal_lightGetMsgId
			<< ", \"length\":0 "
			<< ", \"value\": \"\" }";
	return sstream.str();
}
std::string CAN_min_signals::set_stop_signal_light(bool newValue) {
	std::stringstream sstream;
	sstream << "{\"ID\": " << + m_stop_signal_lightSetMsgId
			<< ", \"length\":1 "
			<< ", \"value\":\""
			<< + newValue
			<< "\"}";
	return sstream.str();
}
