#include "get_analogic_accelerator.h"

void get_analogic_accelerator(){
    analogic_accelerator = analogRead(ANALOGIC_ACCELERATOR);
    //Accelerator value for motor n'est pas envoyé en brut directement, il va encore être transformé avec le régulateur et le limiteur de vitesse
	accelerator_value_for_motor = map(analogic_accelerator, 0, 4092, 0, 255); 
}