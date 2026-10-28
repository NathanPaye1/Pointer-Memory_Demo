#include <iostream>

using namespace std;

void increaseTemp(int* temp, int amount)
{
	if(temp != nullptr)
	{
		*temp += amount;
	}
}

void displayTemp(const int* temp)
{
	if(temp != nullptr)
	{
		cout << "Current Temp: " << *temp << " C\n";
	}
	else
	{
		cout << "No Temperature Sensor Available\n";
	}
}

int main()
{
	cout << "\nMemory Explorer";
	cout << "\n-----------------------------------------\n";

	int cpuTemp = 62;
	int gpuTemp = 55;
	double ramUsage= 7.5;
	char systemStatus = 'N';


	cout << "\nPart 1: Hardware Memory Addresses";
	cout << "\n-----------------------------------------\n";
	cout << "CPU Temp:      " << cpuTemp << " C\n";
	cout << "Address:       " << &cpuTemp << endl;
	cout << "Size:          " << sizeof(cpuTemp) << " Bytes\n\n";

        cout << "GPU Temp:      " << gpuTemp << " C\n";
        cout << "Address:       " << &gpuTemp << endl;
        cout << "Size:          " << sizeof(gpuTemp) << " Bytes\n\n";

        cout << "RAM Usage:     " << ramUsage << " GB\n";
        cout << "Address:       " << &ramUsage << endl;
        cout << "Size:          " << sizeof(ramUsage) << " Bytes\n\n";

        cout << "System Status: " << systemStatus << endl;
        cout << "Address:       " << static_cast<const void*>(&systemStatus) << endl;
        cout << "Size:          " << sizeof(systemStatus) << " Bytes\n";

        cout << "\nPart 2: Hardware Pointers";
        cout << "\n-----------------------------------------\n";

	int* cpuPtr = &cpuTemp;
	double* ramPtr = &ramUsage;

	cout << "CPU Temperature: " << cpuTemp << endl;
	cout << "CPU Address:     " << &cpuTemp << endl;
	cout << "Pointer Stores:  " << cpuPtr << endl;
	cout << "Pointer Address: " << &cpuPtr << endl << endl;

        cout << "Ram Usage:       " << ramUsage << endl;
        cout << "Ram Address:     " << &ramUsage << endl;
        cout << "Pointer Stores:  " << ramPtr << endl;
        cout << "Pointer Address: " << &ramPtr << endl;

        cout << "\nPart 3: Dereferencing Pointers";
        cout << "\n-----------------------------------------\n";

        cout << "CPU Temp:            " << cpuTemp << endl;
        cout << "CPU Pointer Address: " << cpuPtr << endl;
        cout << "CPU Dereferenced:    " << *cpuPtr << endl << endl;

	cout << "RAM Usage:           " << ramUsage << endl;
	cout << "Ram Dereferenced:    " << *ramPtr << endl;

        cout << "\nPart 4: Updating Readings";
        cout << "\n-----------------------------------------\n";

	cout << "Original CPU Temp: " << *cpuPtr << endl;

	//get hotter
	*cpuPtr = 78;

	cout << "Updated CPU Temp:  " << *cpuPtr << endl;
	//sssshhhh
	cout << "Value Through Ptr: " << *cpuPtr << endl;

	//Increase Ram
	*ramPtr+= 1.5;

	cout << "Updated Ram usage: " << *ramPtr << endl;

        cout << "\nPart 5: Sensor Availability";
        cout << "\n-----------------------------------------\n";

	int* sensorPtr = nullptr;

	if(sensorPtr == nullptr)
	{
		cout << "No Temp Sensor Selected\n";
	}

	sensorPtr = &cpuTemp;

	if(sensorPtr != nullptr)
	{
		cout << "CPU Sensor Connected\n";
		cout << "Current Reading: " << *sensorPtr << " C\n";
	}

        cout << "\nPart 6: Switching Sensors";
        cout << "\n-----------------------------------------\n";

	cout << "Active Sensor: CPU\n";
	cout << "Reading: " << *sensorPtr << "C\n";

	//switch to gpu
	sensorPtr = &gpuTemp;

        cout << "Active Sensor: GPU\n";
        cout << "Reading: " << *sensorPtr << "C\n";

	//update temp through pointer
	*sensorPtr = 65;

	cout << "Updated GPU Temp: " << gpuTemp << "C\n";
	cout << "CPU Temp: " << cpuTemp << "C\n";

        cout << "\nPart 7: Pointers vs References";
        cout << "\n-----------------------------------------\n";

	//create reference to cpu temp
	int& cpuRef = cpuTemp;

	//create ptr to cpu Temp
	int* cpuPtr2 = &cpuTemp;

	cout << "CPU Temp:        " << cpuTemp << endl;
	cout << "Reference Value: " << cpuRef << endl;
	cout << "Pointer Value:   " << *cpuPtr2 << endl;

	//modify through reference
	cpuRef = 82;
	cout << "After Modify Using Reference: " << cpuTemp << endl;

	//modify through pointer
	*cpuPtr2 = 85;

	cout << "After Modify Using Pointer:   " << cpuTemp << endl;

        cout << "\nPart 8: Updating Readings using Functions ";
        cout << "\n-----------------------------------------\n";

	cout << "Before CPU Update:\n";
	displayTemp(&cpuTemp);

	//increase by 5C
	increaseTemp(&cpuTemp, 5);

	cout << "After CPU Update:\n";
	displayTemp(&cpuTemp);

	//gpu this time
        cout << "\nBefore GPU Update:\n";
        displayTemp(&gpuTemp);

        //increase by 10C
        increaseTemp(&gpuTemp, 10);

        cout << "After GPU Update:\n";
        displayTemp(nullptr);

        cout << "\nPart 9: Temperature History";
        cout << "\n-----------------------------------------\n";

	//reading over time
	int temps[5] = {62 ,65, 68, 72, 75};

	//ptr to first element
	int* tempPtr = temps;

	cout << "Temperature Readings:\n";
	for(int i = 0; i < 5; i++)
	{
		cout << "Reading " << (i+1) << ". " << temps[i] << " C   Address: " << &temps[i] << endl;
	}

        cout << "\nPart 9: Pointer Arithmetic";
	cout << "\n-----------------------------------------\n";

	cout << "First Reading:  " << *tempPtr << endl;
	cout << "Second reading: " << *(tempPtr + 1) << endl;
	cout << "Third Reading:  " << *(tempPtr + 2) << endl;

	return 0;
}
