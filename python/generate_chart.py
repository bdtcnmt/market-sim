#!/usr/bin/env python
"""
This script reads data from data.json, generates a chart using matplotlib,
and saves the chart as chart.png in the current working directory.
"""

import os
import json
import matplotlib.pyplot as plt
import sys

# Print the current working directory for debugging
cwd = os.getcwd()
print("Current working directory:", cwd)

# Define the path for data.json (expected to be in the current working directory)
data_file = os.path.join(cwd, "data.json")
if not os.path.exists(data_file):
    print("Error: data.json not found at", data_file)
    sys.exit(1)

# Read data from data.json
try:
    with open(data_file, 'r', encoding='utf-8') as f:
        data = json.load(f)
except Exception as e:
    print("Error reading data.json:", e)
    sys.exit(1)

# Extract time series data
time_series = data.get("Time Series (5min)", {})
if not time_series:
    print("No time series data found.")
    sys.exit(1)

# Sort time stamps and extract prices
times = sorted(time_series.keys())
prices = []
for t in times:
    try:
        price = float(time_series[t]["4. close"])
        prices.append(price)
    except (KeyError, ValueError) as e:
        print(f"Error processing data for time {t}: {e}")

if not prices:
    print("No valid price data found.")
    sys.exit(1)

# Create the plot
plt.figure(figsize=(8, 4))
plt.plot(times, prices, marker='o')
plt.xlabel("Time")
plt.ylabel("Close Price")
plt.title("Stock Price Over Time")
plt.xticks(rotation=45)
plt.tight_layout()

# Save chart.png in the current working directory
output_path = os.path.join(cwd, "chart.png")
try:
    plt.savefig(output_path)
    print("Chart saved at:", output_path)
except Exception as e:
    print("Error saving chart:", e)
    sys.exit(1)
