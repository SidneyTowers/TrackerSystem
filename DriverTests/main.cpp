#include <wiringPi.h>
#include <climits>
#include <cstring>
#include <iostream>
#include "../Headers/Motors/GenericMotor.h"
#include "../Headers/Motors/MotorAC.h"
#include "../Headers/Motors/MotorContainer.h"
#include "../Headers/Motors/MotorCustom.h"
#include "../Headers/Motors/MotorDC.h"
#include "../Headers/Motors/MotorDisk.h"
#include "../Headers/Motors/MotorServo.h"
#include "../Headers/Motors/MotorStepper.h"

#define PIN_AC        (-1)
#define PIN_CUSTOM    (-1)
#define PIN_DC        (-1)
#define PIN_DISK      (-1)
#define PIN_SERVO     (1)
#define PIN_STEPPER_1 (5)
#define PIN_STEPPER_2 (6)
#define PIN_STEPPER_3 (7)
#define PIN_STEPPER_4 (21)


std::string passOrFail(const std::string title, bool cond) {
	return title + ":\t" + (cond? "[PASS]": "[FAIL]") + "\n";
}


void test__container() {
	std::cout << "<<<TEST MOTOR CONTAINER>>>" << std::endl;
	
	MotorContainer container;
	std::cout << passOrFail("Create empty container", container.size() == 0);
	
	container.push_back(new MotorAC(1));
	std::cout << passOrFail("Add motor", container.size() == 1);
	
	container.push_back(new MotorCustom(2));
	std::cout << passOrFail("Add motor", container.size() == 2);
	
	container.push_back(new MotorDC(3));
	std::cout << passOrFail("Add motor", container.size() == 3);
	
	container.push_back(new MotorDisk(4));
	std::cout << passOrFail("Add motor", container.size() == 4);
	
	container.push_back(new MotorServo(5));
	std::cout << passOrFail("Add motor", container.size() == 5);
	
	const std::vector<int> PINS {6, 7, 8, 9};
	container.push_back(new MotorStepper(PINS));
	std::cout << passOrFail("Add motor", container.size() == 6);
	
	container.updateAll();
	std::cout << passOrFail("Update all", true);
}


void test__Motor_Move(GenericMotor *mot, int error) {
	mot->setError(error);
	// std::cout << passOrFail("Set motor position " + std::to_string(error), mot->getPosition() == position);
}
void test__Motor_Update(GenericMotor *mot) {
	mot->update();
	std::cout << passOrFail("Updating motor", true);
}
void test__Motor(GenericMotor *mot) {
	std::cout << "--POSITION CHECK--" << std::endl;
	test__Motor_Move(mot, 0);
	test__Motor_Move(mot, 1);
	test__Motor_Move(mot, -1);
	test__Motor_Move(mot, INT_MAX);
	test__Motor_Move(mot, -INT_MAX);
	
	
	std::cout << "--UPDATE CHECK--" << std::endl;
	test__Motor_Update(mot);
	
	
	std::cout << std::endl;
}

void test__ac() {
	std::cout << "<<<TEST AC MOTOR>>>" << std::endl;
	MotorAC mot(PIN_AC);
	test__Motor(&mot);
}

void test__custom() {
	std::cout << "<<<TEST CUSTOM MOTOR>>>" << std::endl;
	MotorCustom mot(PIN_CUSTOM);
	test__Motor(&mot);
}

void test__dc() {
	std::cout << "<<<TEST DC MOTOR>>>" << std::endl;
	MotorDC mot(PIN_DC);
	test__Motor(&mot);
}

void test__disk() {
	std::cout << "<<<TEST DISK MOTOR>>>" << std::endl;
	MotorDisk mot(PIN_DISK);
	test__Motor(&mot);
}

void test__servo() {
	std::cout << "<<<TEST SERVO MOTOR>>>" << std::endl;
	
	
	MotorServo mot(PIN_SERVO);
	test__Motor(&mot);
	
	std::cout << "Sweeping..." << std::endl;
	for (int i = MOTOR_SERVO_MIN_POSITION; i < MOTOR_SERVO_MAX_POSITION; i++) {
		// mot.setError(1);
		// mot.update();
		mot.move(1);
		delay(50);
	}
	for (int i = MOTOR_SERVO_MAX_POSITION; i >= MOTOR_SERVO_MIN_POSITION; i--) {
		// mot.setError(-1);
		// mot.update();
		mot.move(-1);
		delay(50);
	}
}

void test__stepper() {
	std::cout << "<<<TEST STEPPER MOTOR>>>" << std::endl;
	MotorStepper mot(std::vector<int>({
		PIN_STEPPER_1,
		PIN_STEPPER_2,
		PIN_STEPPER_3,
		PIN_STEPPER_4
	}));
	test__Motor(&mot);
	
	std::cout << "Sweeping..." << std::endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 1000; j++) {
			if (i % 2 == 0)
				mot.move(1);
			else
				mot.move(-1);
			delay(2);
		}
	}
}


int main() {
	if(wiringPiSetup() == -1){ // when initialize wiring fails, print message to screen
        std::cout << "setup wiringPi failed!" << std::endl;
        return 1; 
    }
	
	// test__ac();
	// test__custom();
	// test__dc();
	// test__disk();
	test__servo();
	test__stepper();
	test__container();
	
	
	std::cout << "<<<TEST END>>>" << std::endl;
}
