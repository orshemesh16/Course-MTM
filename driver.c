#include "driver.h"
#include "team.h"
#include "season.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct driver {
        int id;
        char* name;
        Team team;
        int points;
        Season season;
};

static bool UpdateAllocationMemoryStatus(DriverStatus* status, void* p){
    if (p == NULL) {
        *status=DRIVER_MEMORY_ERROR;
        return false;
    }
    *status=DRIVER_STATUS_OK;
    return true;
}

Driver DriverCreate(DriverStatus* status, char* driver_name, int driverId){
    Driver driver = malloc(sizeof(*driver));
    if (!UpdateAllocationMemoryStatus(status, driver)) return NULL;
    char* driver_name_copy = malloc(sizeof(*driver_name_copy)*(strlen(driver_name)+1));
    if (!UpdateAllocationMemoryStatus(status, driver->name)) return NULL;
    strcpy(driver_name_copy, driver_name);
    driver->id = driverId;
    driver->name = driver_name_copy;
    return driver;
}

void   DriverDestroy(Driver driver){
    free(driver->name);
    free(driver);
}

const char* DriverGetName(Driver driver){
    if (driver == NULL) return NULL;
    return driver->name;
}

Team  DriverGetTeam(Driver driver){
    if (driver == NULL) return NULL;
    return driver->team;
}

int DriverGetId(Driver driver){
    if (driver == NULL) return NULL;
    return driver->id;
}

void  DriverSetTeam(Driver driver, Team team){
    driver->team = team;
}

void  DriverSetSeason(Driver driver, Season season){
    
}