//24K-0673
//HATIM MUSTAFA

#include <iostream>
#include <string>
using namespace std;

class Vehicle {
    public:
    string id;
    static int deliveries;

    protected:
    float efficiency;

    Vehicle (string id, float e) : id(id), efficiency(e) {}

    virtual void calcBestRoute () {
        cout << id << " calculating standard route.\n"; 
    }

    void move () {
        calcBestRoute();
        cout << "Vehicle is moving\n";
        deliveries++;
    }

    virtual void estimateDeliveryTime () {
        cout << id << " estimating standard delivery time.\n"; 
    }

    virtual void command (string command, string packageID, string urgency = "normal") {}

    bool operator == (const Vehicle& other) const {
        if (this->efficiency > other.efficiency) {
            return true;
        }
        else {
            return false;
        }
    }

    friend string resolveConflict(Vehicle& v1, Vehicle& v2);
};

int Vehicle::deliveries = 0;

class RamzanDrone : public Vehicle {
    private:
    bool highSpeedMode;

    public:
    RamzanDrone(string id, float e) : Vehicle(id, e), highSpeedMode(false) {}

    void calcBestRoute () override {
        cout << id << " calculating aerial route for fast delivery.\n";
    }

    void estimateDeliveryTime() override {
        cout << id << " estimating fast air-based delivery time.\n";
    }

    void command (string command, string packageID, string urgency = "normal") override {
        if (urgency == "urgent") {
            highSpeedMode = true;
            cout << "High speed mode turned on\n";
        }
        else {
            highSpeedMode = false;
        }
        calcBestRoute();
        cout << id << " delivering package " << packageID << " via drone with " << urgency << " priority.\n";
        deliveries++;
    }

};

class RamzanTimeShip : public Vehicle {
    private:
    bool historicalConsistency;

    public:
    RamzanTimeShip(string id, float e) : Vehicle(id, e) {}

    void calcBestRoute () override {
        cout << id << " verifying historical consistency before delivery.\n";
    }

    void estimateDeliveryTime() override {
        cout << id << " calculating time-travel optimized schedule.\n";
    }

    void command (string command, string packageID, string urgency = "normal") override {
        if (urgency == "urgent") {
            historicalConsistency = true;
            cout << "Historical consistency is being thouroughly validated\n";
        }
        else {
            historicalConsistency = false;
        }
        calcBestRoute();
        cout << id << " ensuring accurate historical delivery for " << packageID << " with " << urgency << " priority.\n";
        deliveries++;
    }
};

class RamzanHyperPod : public Vehicle {
    protected:
    bool emergencyRoute;
    public:
    RamzanHyperPod(string id, float e) : Vehicle(id, e), emergencyRoute(false) {}

    void calcBestRoute() override {
        cout << id << " navigating underground tunnel network.\n";
    }
    void estimateDeliveryTime() override {
        cout << id << " optimizing bulk delivery schedule.\n";
    }

    void command (string command, string packageID, string urgency = "normal") override {
        if (urgency == "urgent") {
            emergencyRoute = true;
            cout << "Using emergency routes\n";
        }
        else {
            emergencyRoute = false;
        }
        calcBestRoute();
        cout << id << " transporting bulk package " << packageID << " via hyperloop pod with " << urgency << " priority.\n";
        deliveries++;
    }
};

string resolveConflict(Vehicle& v1, Vehicle& v2) {
    if (v1 == v2) return v1.id;
    return v2.id;
}

int main() {
    RamzanDrone drone("Drone-X1", 0.7);
    RamzanTimeShip timeShip("TimeShip-42", 0.75);
    RamzanHyperPod hyperPod("HyperPod-99", 0.6);

    cout << "\nExecuting Deliveries:\n";
    cout <<"-------------------------------------------------\n";
    drone.command("deliver", "IFT123", "urgent");
    cout <<"-------------------------------------------------\n";
    timeShip.command("deliver", "HIST789");
    cout <<"-------------------------------------------------\n";
    hyperPod.command("deliver", "BULK456", "urgent");
    cout <<"-------------------------------------------------\n";

    cout << "Total Deliveries Active: " << Vehicle::deliveries << "\n";
    
    cout << "\nConflict Resolution Test:\n";
    cout << "Better vehicle for priority delivery: " << resolveConflict(drone, hyperPod) << "\n";
}

