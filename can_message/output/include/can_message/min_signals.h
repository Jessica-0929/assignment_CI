#ifndef HEADER_MIN_SIGNALS_H
#define HEADER_MIN_SIGNALS_H

#include <string>
class CAN_min_signals {
	public:
		CAN_min_signals();
		std::string get_temperature();
		std::string set_temperature(float newValue);
		std::string get_humidity();
		std::string set_humidity(uint8_t newValue);
		std::string get_front_sensor_status();
		std::string set_front_sensor_status(bool newValue);
		std::string get_flow_rate();
		std::string set_flow_rate(uint16_t newValue);
		std::string get_flow_meter_sensor_status();
		std::string set_flow_meter_sensor_status(uint8_t newValue);
		std::string get_light_intensity();
		std::string set_light_intensity(uint8_t newValue);
		std::string get_light_intensity_sensor_status();
		std::string set_light_intensity_sensor_status(uint8_t newValue);
		std::string get_water_level();
		std::string set_water_level(uint8_t newValue);
		std::string get_water_level_sensor_status();
		std::string set_water_level_sensor_status(uint8_t newValue);
		std::string get_soil_moisture();
		std::string set_soil_moisture(uint8_t newValue);
		std::string get_soil_moisture_sensor_status();
		std::string set_soil_moisture_sensor_status(uint8_t newValue);
		std::string get_stop_signal_light();
		std::string set_stop_signal_light(bool newValue);
	private:
		uint8_t m_startMsgId;
		uint8_t m_temperatureGetMsgId;
		uint8_t m_temperatureSetMsgId;
		uint8_t m_humidityGetMsgId;
		uint8_t m_humiditySetMsgId;
		uint8_t m_front_sensor_statusGetMsgId;
		uint8_t m_front_sensor_statusSetMsgId;
		uint8_t m_flow_rateGetMsgId;
		uint8_t m_flow_rateSetMsgId;
		uint8_t m_flow_meter_sensor_statusGetMsgId;
		uint8_t m_flow_meter_sensor_statusSetMsgId;
		uint8_t m_light_intensityGetMsgId;
		uint8_t m_light_intensitySetMsgId;
		uint8_t m_light_intensity_sensor_statusGetMsgId;
		uint8_t m_light_intensity_sensor_statusSetMsgId;
		uint8_t m_water_levelGetMsgId;
		uint8_t m_water_levelSetMsgId;
		uint8_t m_water_level_sensor_statusGetMsgId;
		uint8_t m_water_level_sensor_statusSetMsgId;
		uint8_t m_soil_moistureGetMsgId;
		uint8_t m_soil_moistureSetMsgId;
		uint8_t m_soil_moisture_sensor_statusGetMsgId;
		uint8_t m_soil_moisture_sensor_statusSetMsgId;
		uint8_t m_stop_signal_lightGetMsgId;
		uint8_t m_stop_signal_lightSetMsgId;
};
#endif
