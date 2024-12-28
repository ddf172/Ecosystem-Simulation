import matplotlib.pyplot as plt
import pandas as pd

def plot_statistics(csv_file, output_image):
    # Load the CSV file into a DataFrame
    try:
        data = pd.read_csv(csv_file)
    except FileNotFoundError:
        print(f"Error: The file '{csv_file}' does not exist.")
        return
    except Exception as e:
        print(f"Error reading the CSV file: {e}")
        return

    # Ensure the expected columns are in the data
    expected_columns = [
        "Turn",
        "CarnivoreDeaths",
        "HerbivoreDeaths",
        "OmnivoreDeaths",
        "CarnivoresAlive",
        "HerbivoresAlive",
        "OmnivoresAlive",
    ]
    if not all(col in data.columns for col in expected_columns):
        print("Error: CSV file does not contain the expected columns.")
        return

    # Plot deaths
    plt.figure(figsize=(12, 6))
    plt.plot(data["Turn"], data["CarnivoreDeaths"], label="Carnivore Deaths", linestyle="--", color="red")
    plt.plot(data["Turn"], data["HerbivoreDeaths"], label="Herbivore Deaths", linestyle="--", color="green")
    plt.plot(data["Turn"], data["OmnivoreDeaths"], label="Omnivore Deaths", linestyle="--", color="blue")

    # Plot alive counts
    plt.plot(data["Turn"], data["CarnivoresAlive"], label="Carnivores Alive", linestyle="-", color="darkred")
    plt.plot(data["Turn"], data["HerbivoresAlive"], label="Herbivores Alive", linestyle="-", color="darkgreen")
    plt.plot(data["Turn"], data["OmnivoresAlive"], label="Omnivores Alive", linestyle="-", color="darkblue")

    # Labeling and legend
    plt.title("Animal Statistics Over Time")
    plt.xlabel("Turn")
    plt.ylabel("Count")
    plt.legend()
    plt.grid(True)

    # Save the plot as a PNG file
    plt.savefig(output_image, format="png")
    plt.close()
    print(f"Plot saved as {output_image}")

# Example usage
if __name__ == "__main__":
    csv_file = "Files/statistics.csv"  # Replace with the path to your CSV file
    output_image = "Files/statistics_plot.png"  # Replace with the desired output image name
    plot_statistics(csv_file, output_image)
