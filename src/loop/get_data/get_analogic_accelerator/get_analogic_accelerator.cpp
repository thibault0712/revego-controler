#include "get_analogic_accelerator.h"

void get_analogic_accelerator(){
    analogic_accelerator = analogRead(ANALOGIC_ACCELERATOR);
    //Accelerator value for motor n'est pas envoyé en brut directement, il va encore être transformé avec le régulateur vitesse et le limiteur de vitesse
	accelerator_value_for_motor = map(analogic_accelerator, 840, 1900, 0, 255); 
    if (accelerator_value_for_motor > 255){
        accelerator_value_for_motor = 255;
    }else if(accelerator_value_for_motor < 0){
        accelerator_value_for_motor = 0;
    }
}