#ifndef ECOSYSTEM_SIMULATION_MOVEACTIONCHOOSERNEARESTRESOURCETILE_H
#define ECOSYSTEM_SIMULATION_MOVEACTIONCHOOSERNEARESTRESOURCETILE_H

#include "../IActionChooser.h"

class MoveActionChooserNearestResourceTile : public IActionChooser{
private:
    std::vector<std::shared_ptr<Tile>> tilesWithResources;
public:
    /**
     * Contract: tilesWithResources has to be within reaching distance of the animal
     * Constructor for MoveActionChooserNearestResourceTile
     * @param tilesWithResources vector of tiles with resources
     */
    explicit MoveActionChooserNearestResourceTile(std::vector<std::shared_ptr<Tile>>& tilesWithResources);

    MoveActionChooserNearestResourceTile();

    std::shared_ptr<Action> chooseAction(Animal* animal) override;
    ~MoveActionChooserNearestResourceTile() override;

    void setTilesWithResources(std::vector<std::shared_ptr<Tile>>& newTilesWithResources);
};


#endif //ECOSYSTEM_SIMULATION_MOVEACTIONCHOOSERNEARESTRESOURCETILE_H
