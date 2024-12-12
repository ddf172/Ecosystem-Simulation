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
    /**
     * Contract: tilesWithResources has to be within reaching distance of the animal
     * Constructor for MoveActionChooserNearestResourceTile
     * @param tilesWithResources vector of tiles with resources
     */
    explicit MoveActionChooserNearestResourceTile(std::vector<Tile*>& tilesWithResources);
    Action* chooseAction(Animal* animal) override;
    ~MoveActionChooserNearestResourceTile() override = default;
};


#endif //ECOSYSTEM_SIMULATION_MOVEACTIONCHOOSERNEARESTRESOURCETILE_H