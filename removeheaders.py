import re

def remove_comments_before_includes(file_path):
    """
    Removes all comments (single-line and multi-line) and leading whitespace
    that appear before the first #include directive in a C++ file.

    Parameters:
        file_path (str): Path to the C++ file to modify.

    Returns:
        None: The file is modified in place.
    """
    try:
        with open(file_path, 'r') as file:
            content = file.read()

        # Split content into pre-include and post-include parts
        match = re.search(r'^(.*?)(#include\s+<[^>]+>|#include\s+"[^"]+")', content, re.DOTALL)

        if match:
            pre_include = match.group(1)
            include_and_rest = content[len(pre_include):]

            # Remove all single-line and multi-line comments and leading whitespace from the pre-include part
            cleaned_pre_include = re.sub(r'//.*?$|/\*.*?\*/', '', pre_include, flags=re.DOTALL | re.MULTILINE)
            cleaned_pre_include = re.sub(r'^\s+', '', cleaned_pre_include, flags=re.DOTALL)

            # Combine cleaned pre-include content with the rest of the file
            cleaned_content = cleaned_pre_include + include_and_rest

            # Write the modified content back to the file
            with open(file_path, 'w') as file:
                file.write(cleaned_content)
        else:
            print(f"No #include directive found in {file_path}. No changes made.")
    except Exception as e:
        print(f"Error processing file {file_path}: {e}")

# List of files to process
files = [
    "General/Application.h",
    "General/Application.cpp",
    "General/SimulationEngine/Grid.cpp",
    "General/SimulationEngine/Grid.h",
    "General/SimulationEngine/Tile.h",
    "General/SimulationEngine/Tile.cpp",
    "General/SimulationEngine/SimulationManager.h",
    "General/SimulationEngine/SimulationManager.cpp",
    "Simulation/Animals/Animal.h",
    "Simulation/Animals/Animal.cpp",
    "Simulation/Resources/GrassResource.h",
    "Simulation/Resources/Resource.h",
    "Simulation/Resources/Resource.cpp",
    "Simulation/Resources/GrassResource.cpp",
    "Simulation/Resources/ResourceTypeEnum.h",
    "Simulation/Animals/HerbivoreAnimal.cpp",
    "Simulation/Animals/HerbivoreAnimal.h",
    "Utilities/Utilities.h",
    "Utilities/Utilities.cpp",
    "Simulation/Actions/Action.h",
    "Simulation/Actions/Action.cpp",
    "Simulation/Actions/ActionTypeEnum.h",
    "Simulation/Actions/ActionMove.cpp",
    "Simulation/Actions/ActionMove.h",
    "Simulation/Actions/ActionEat.cpp",
    "Simulation/Actions/ActionEat.h",
    "Simulation/Animals/AnimalTypeEnum.h",
    "Simulation/Actions/ActionNone.cpp",
    "Simulation/Actions/ActionNone.h",
    "Simulation/Actions/ActionDie.cpp",
    "Simulation/Actions/ActionDie.h",
    "General/Rendering/Renderer.cpp",
    "General/Rendering/Renderer.h",
    "General/Rendering/GraphicTile.cpp",
    "General/Rendering/GraphicTile.h",
    "Utilities/MergingContainer.h",
    "Simulation/Brains/Brain.cpp",
    "Simulation/Brains/Brain.h",
    "Simulation/ActionChoosers/IActionChooser.h",
    "Simulation/ActionChoosers/EatActionChoosers/EatActionChooserDefault.cpp",
    "Simulation/ActionChoosers/EatActionChoosers/EatActionChooserDefault.h",
    "Simulation/ActionChoosers/MoveActionChoosers/MoveActionChooserNearestResourceTile.cpp",
    "Simulation/ActionChoosers/MoveActionChoosers/MoveActionChooserNearestResourceTile.h",
    "Simulation/ActionChoosers/DieActionChoosers/DieActionChooserDefault.cpp",
    "Simulation/ActionChoosers/DieActionChoosers/DieActionChooserDefault.h",
    "Simulation/Resources/MeatResource.cpp",
    "Simulation/Resources/MeatResource.h",
    "Simulation/Actions/ActionReproduce.cpp",
    "Simulation/Actions/ActionReproduce.h",
    "Simulation/ActionChoosers/ReproduceActionChoosers/ReproduceActionChooserSoloDefault.cpp",
    "Simulation/ActionChoosers/ReproduceActionChoosers/ReproduceActionChooserSoloDefault.h",
    "Simulation/Actions/ActionAttack.cpp",
    "Simulation/Actions/ActionAttack.h",
    "Simulation/ActionChoosers/AttackActionChoosers/AttackActionChooserDefault.cpp",
    "Simulation/ActionChoosers/AttackActionChoosers/AttackActionChooserDefault.h",
    "Simulation/Animals/CarnivoreAnimal.cpp",
    "Simulation/Animals/CarnivoreAnimal.h",
    "Utilities/FileHandling/SettingsCSVReader.cpp",
    "Utilities/FileHandling/SettingsCSVReader.h",
    "Utilities/StatisticsManager.cpp",
    "Utilities/StatisticsManager.h",
    "Simulation/Spawners/Spawner.cpp",
    "Simulation/Spawners/Spawner.h",
]

# Process each file
for file in files:
    remove_comments_before_includes(file)