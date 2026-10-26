#include <iostream>

using namespace std;

int main()
{
	cout << "\nMemory Explorer";
	cout << "\n---------------------------------\n";

	int cpuTemp = 62;
	int gpuTemp = 55;
	double ramUsage= 7.5;
	char systemStatus = 'N';


	cout << "\nPart 1: Hardware Memory Addresses";
	cout << "\n---------------------------------\n";
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
        cout << "\n---------------------------------\n";

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
        cout << "\n---------------------------------\n";

        cout << "CPU Temp:            " << cpuTemp << endl;
        cout << "CPU Pointer Address: " << cpuPtr << endl;
        cout << "CPU Dereferenced:    " << *cpuPtr << endl << endl;

	cout << "RAM Usage:           " << ramUsage << endl;
	cout << "Ram Dereferenced:    " << *ramPtr << endl;

        cout << "\nPart 4: Updating Readings";
        cout << "\n---------------------------------\n";

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
        cout << "\n---------------------------------\n";

	int* sensorPtr = nullptr;

	if(sensorPtr == nullptr)
	{
		cout << "No Temp Sensor Selected\n";
	}

	sensorPtr = &cpuTemp;

	if(sensorPtr != nullptr)
	{
		cout << "CPU Sensor Connected\n";
		cout << "Current Reading: " << *sensorPtr << " C\n\n";
	}

	return 0;
}
