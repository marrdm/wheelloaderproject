#include analogOutPacket.h

void setAnalogOut(EBU_analog_out_packet *packet, int channel, float value){
	uint16_t intValue;
	
	if(value > 5){
		intValue = 65535; // Maximum value of a 16 bit integer.
	} else if(value < 0){
		intValue = 0;
	}else{
		intValue = ((value/5) * 65535 + 0.5); //Rounding conversion from float to int.
	}
	
	// The EBU expects the least significant bit first and I MAY have to reverse intValue to achive this.
	packet->channel[channel] = intValue;	
}

float getAnalogOut(EBU_analog_out_packet *packet, int channel){
	
	uint16_t intValue = packet->channel[channel];
	
	float value = ((intValue/65535) * 5);
	return value;
}
