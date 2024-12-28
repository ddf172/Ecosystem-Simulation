import matplotlib.pyplot as plt
import pandas as pd

def plot_statistics(csv_file, output_image):
    try:
        data = pd.read_csv(csv_file)
    except FileNotFoundError:
        print(f"Error: The file '{csv_file}' does not exist.")
        return
    except Exception as e:
        print(f"Error reading the CSV file: {e}")
        return

    expected_columns = [
        "Turn",
        "CarnivoreDeaths",
        "HerbivoreDeaths",
        "CarnivoresAlive",
        "HerbivoresAlive",
    ]
    if not all(col in data.columns for col in expected_columns):
        print("Error: CSV file does not contain the expected columns.")
        return

        
    plt.figure(figsize=(12, 6))
    plt.plot(data["Turn"], data["CarnivoreDeaths"], label="Carnivore Deaths", linestyle="--", color="red")
    plt.plot(data["Turn"], data["HerbivoreDeaths"], label="Herbivore Deaths", linestyle="--", color="green")

    plt.plot(data["Turn"], data["CarnivoresAlive"], label="Carnivores Alive", linestyle="-", color="darkred")
    plt.plot(data["Turn"], data["HerbivoresAlive"], label="Herbivores Alive", linestyle="-", color="darkgreen")

    plt.title("Animal Statistics Over Time")
    plt.xlabel("Turn")
    plt.ylabel("Count")
    plt.legend()
    plt.grid(True)
    plt.savefig(output_image, format="png")
    plt.close()
    print(f"Plot saved as {output_image}")

if __name__ == "__main__":
    csv_file = "Files/statistics.csv"
    output_image = "Files/statistics_plot.png"
    plot_statistics(csv_file, output_image)
