# 按鈕控制 LED 燈條顯示顏色專案

這個專案使用 Adafruit NeoPixel 庫來控制 WS2812 LED 燈條的顏色，並且通過按鈕來調整顯示的燈數。每次按下按鈕，會依次點亮 LED 燈條的單元，直到達到總 LED 數量，然後重置為初始狀態。

## 硬體需求

- **Arduino 開發板**（如 Arduino Uno、Mega 等）
- **WS2812 LED 燈條**（例如 NeoPixel 燈條）
- **按鈕**（用來控制 LED 顯示的開關）
- **電源**（適合電燈條的電壓）

## 引腳配置

| 引腳          | 描述          |
| ------------- | ------------- |
| `LED_PIN`     | 連接 NeoPixel 燈條的數字輸入引腳（控制燈條顯示） |
| `BUTTON_PINS` | 連接按鈕的數字輸入引腳（用來控制燈條顯示數量） |

## 軟體需求

- Arduino IDE
- Adafruit NeoPixel 庫

## 安裝 Adafruit NeoPixel 庫

在 Arduino IDE 中，請按以下步驟安裝 Adafruit NeoPixel 庫：

1. 打開 Arduino IDE。
2. 點擊 **工具** > **管理庫**。
3. 在庫管理器中搜尋 **Adafruit NeoPixel**。
4. 點擊安裝。

## 程式碼說明

### 主要程式結構

- **按鈕控制**：
  每當按鈕被按下，`unit` 變數會增加 1，這表示燈條顯示更多的 LED 單元。
  
- **顯示顏色**：
  當 `unit` 增加時，對應的 LED 單元會變為白色（RGB：255, 255, 255）。當 `unit` 超過設定的最大 LED 數量（`NUM_LEDS_TOTAL`），會重置並熄燈。

### 重要變數和函數

- `unit`：當前已顯示的 LED 單元數。
- `setunitColor(int red, int green, int blue)`：設置指定數量的 LED 單元顯示指定顏色。
- `ifBotton()`：檢查按鈕是否被按下，並返回相應的狀態。

### 顏色設定

顏色會通過 RGB 值來設置，在這個範例中使用的是「白」(RGB: 255, 255, 255)，您可以根據需要修改此值來顯示不同顏色。

### 按鈕邏輯

按鈕被按下時，`unit` 變數增加，表示燈條顯示更多的 LED 單元。一旦 `unit` 超過最大燈數（`NUM_LEDS_TOTAL`），會觸發重置，所有 LED 熄燈，並將 `unit` 重置為 0。

## 使用方法

1. 下載並安裝 Arduino IDE。
2. 下載或複製此專案的程式碼。
3. 打開 Arduino IDE，將程式碼貼入編輯器。
4. 將 Arduino 透過 USB 連接到電腦，並選擇對應的開發板型號和端口。
5. 點擊 **上傳** 按鈕，將程式碼上傳到 Arduino。
6. 點擊按鈕控制 LED 燈條的顯示。

## 參數調整

- `NUM_LEDS_TOTAL`：總 LED 燈條的數量，可以根據你的實際燈條調整。
- `LED_PIN`：設定控制 LED 的引腳，根據你連接的引腳進行修改。
- `BUTTON_PINS`：設定按鈕引腳，根據你使用的引腳進行修改。
