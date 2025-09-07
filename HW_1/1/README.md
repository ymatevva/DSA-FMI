# HW1 - Browser Tabs Management 

This project implements a tab management system for a browser. Each tab stores a URL and a timestamp representing the time when the page was loaded. The program allows managing multiple tabs, navigating between them, opening and closing tabs, and visiting web pages via a command-line interface.

## Features

- Each tab contains:
  - `URL` (string): Current page loaded in the tab.
  - `timestamp` (integer): Unix timestamp of when the page was loaded.

- Only one tab is **current** at any moment.
- Navigate between tabs using back/forward operations.
- Open, close, and insert new tabs.
- Automatic timestamp updates when pages are loaded.
- Always ensures at least one tab is open (default: `"about:blank"`).

## Commands

The program provides the following command-line commands:

- `GO <url>`  
  Load the page `<url>` in the current tab. Updates the tab’s timestamp automatically.

- `INSERT <url>`  
  Opens a new tab **after the current one** with URL `<url>`. Updates the timestamp. The new tab becomes current.

- `BACK`  
  Move to the tab immediately before the current tab. No action if already at the first tab.

- `FORWARD`  
  Move to the tab immediately after the current tab. No action if already at the last tab.

- `REMOVE`  
  Close the current tab. The current tab becomes the next tab if available; otherwise, the previous tab. If it was the only tab, opens a new tab with URL `"about:blank"`.

- `PRINT`  
  Display all tabs in order. The current tab is marked with a `>` symbol. Format:  

- `SORT <by>`  
Sort tabs and make the first one current.
- `<by>` can be:
  - `URL`: Sort lexicographically by URL; ties broken by timestamp.
  - `TIME`: Sort by timestamp; ties broken by URL.


