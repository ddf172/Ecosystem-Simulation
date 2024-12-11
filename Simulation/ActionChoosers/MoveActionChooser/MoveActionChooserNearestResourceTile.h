//
// Created by ddf on 11.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_MOVEACTIONCHOOSERNEARESTRESOURCETILE_H
#define ECOSYSTEM_SIMULATION_MOVEACTIONCHOOSERNEARESTRESOURCETILE_H

#include "../IActionChooser.h"

class MoveActionChooserNearestResourceTile : public IActionChooser{
private:
    std::vector<Tile*>& tilesWithResources;
public:
    explicit MoveActionChooserNearestResourceTile(std::vector<Tile*>& tilesWithResources);
    Action* chooseAction(Animal* animal) override;
    ~MoveActionChooserNearestResourceTile() override = default;
};


#endif //ECOSYSTEM_SIMULATION_MOVEACTIONCHOOSERNEARESTRESOURCETILE_H
