# Literały w C++

Materiały, ćwiczenia i quiz o literałach w C++: wbudowane, surowe i definiowane przez użytkownika.

## Czym są literały?

Literał to wartość zapisana wprost w kodzie: `42`, `2.5f`, `"Ala"`, `R"(C:\dane)"`. O jego typie decyduje sam
zapis — system liczbowy, przedrostek i sufiks — więc `"Ala"` to tablica znaków, a `"Ala"s` już `std::string`.
Od C++11 można definiować własne sufiksy (`4_kib`, `2.4_ghz`): literał staje się wywołaniem funkcji
`operator""`, która może zwrócić typ z jednostką. Dzięki temu jednostka jest częścią typu, a z `consteval`
błędna wartość literału jest wykrywana już podczas kompilacji.
Więcej w [`lab/_start.ipynb`](lab/_start.ipynb).

## Struktura

- [`lab/`](lab/) — notebooki JupyterLab z materiałami i ćwiczeniami; zacznij od [`lab/_start.ipynb`](lab/_start.ipynb)
  - [`lab/01_builtin/`](lab/01_builtin/) — literały wbudowane, surowe napisy, `std::literals`
    ([notebook](lab/01_builtin/01_builtin.ipynb))
  - [`lab/02_udl/`](lab/02_udl/) — literały definiowane przez użytkownika
    ([notebook](lab/02_udl/02_udl.ipynb)); ćwiczenia
    [`ex1_distance`](lab/02_udl/ex1_distance/), [`ex2_angle`](lab/02_udl/ex2_angle/),
    [`ex3_speed`](lab/02_udl/ex3_speed/)
  - [`lab/03_compile_time/`](lab/03_compile_time/) — literały `constexpr` i `consteval`
    ([notebook](lab/03_compile_time/03_compile_time.ipynb)); ćwiczenia
    [`ex4_color`](lab/03_compile_time/ex4_color/), [`ex5_duration`](lab/03_compile_time/ex5_duration/)
  - [`lab/cmake/lab.cmake`](lab/cmake/lab.cmake) — wspólne ustawienia CMake (C++20, GoogleTest)
- [`pyproject.toml`](pyproject.toml) — środowisko Pythona dla notebooków (zarządzane przez [uv](https://docs.astral.sh/uv/))

## Wymagania

- kompilator C++20: GCC 11+, Clang 14+ (Visual Studio 2022 i Apple Clang 15 powinny działać, ale nie były testowane),
- CMake 3.22+,
- Python 3.10+ i JupyterLab 4,
- internet przy pierwszej kompilacji (CMake pobiera GoogleTest 1.18.0 do `lab/_deps`).

Szczegóły i komórka sprawdzająca środowisko — w `lab/_start.ipynb`.

## Jak zacząć

Z [uv](https://docs.astral.sh/uv/):

```bash
uv sync
uv run --with jupyterlab jupyter lab lab/_start.ipynb
```

Bez uv — zwykłe środowisko wirtualne Pythona:

```bash
python3 -m venv .venv
source .venv/bin/activate        # Windows: .venv\Scripts\activate
pip install jupyterlab
jupyter lab lab/_start.ipynb
```

W notebooku `_start` uruchom komórki z sekcji „Sprawdzenie środowiska” — jeśli testy przejdą, kompilator,
CMake i GoogleTest są gotowe.

## Autorzy

- Tomasz Idźkowski (idzkowskit@student.agh.edu.pl)
- Kacper Kobieluch (kkobieluch@student.agh.edu.pl)
- Maksymilian Koleśniak (mkolesniak@student.agh.edu.pl)
