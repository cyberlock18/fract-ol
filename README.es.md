![fractol](fractol.PNG)
# fract-ol

Un renderizador de fractales interactivo desarrollado en C como parte del currículo de la escuela 42. Usa la biblioteca gráfica MiniLibX para mostrar y explorar los conjuntos de **Mandelbrot** y **Julia** en tiempo real.

---

## Lo que aprendí / Habilidades adquiridas

- **Matemáticas de números complejos** — comprensión de cómo las fórmulas iterativas generan geometría fractal
- **Programación gráfica con MiniLibX** — renderizado de píxeles directamente en una ventana usando X11
- **Manejo de eventos** — hooks de teclado y ratón para zoom, desplazamiento y cambios de color interactivos
- **Gestión de memoria en C** — manejo de buffers de imagen y recursos de ventana sin fugas de memoria
- **Estructuración de Makefiles** — organización de un proyecto C multi-archivo con dependencias de bibliotecas (`libft`, MiniLibX)
- **Teoría del color** — implementación de múltiples esquemas de mapeo de color (clásico, cálido, frío, pastel, púrpura, cian)
- **Precisión en punto flotante** — mapeo de coordenadas de pantalla al plano complejo con zoom y desplazamiento

---

## Compilación y ejecución

### Requisitos previos

- Linux con X11 (o entorno compatible)
- `cc` (compilador de C)
- Biblioteca MiniLibX para Linux (incluida como `minilibx-linux` dentro del directorio del proyecto)
- `libft` (incluida como `libft` dentro del directorio del proyecto)

### Compilar

```bash
cd fract-ol
make
```

Esto genera el binario `fractol`.

### Limpiar

```bash
make clean    # elimina los archivos objeto
make fclean   # elimina los archivos objeto y el binario
make re       # recompilación completa
```

### Ejecutar

```bash
# Conjunto de Mandelbrot
./fractol mandelbrot

# Conjunto de Julia (requiere dos parámetros de punto flotante: parte real e imaginaria de la constante)
./fractol julia -0.4 0.6
./fractol julia 0.285 0.01
```

Si no se proporciona un argumento válido, el programa muestra la información de uso y termina.

---

## Uso y controles

| Acción | Control |
|---|---|
| Acercar zoom | Rueda del ratón hacia arriba |
| Alejar zoom | Rueda del ratón hacia abajo |
| Desplazarse | Teclas de flecha |
| Cambiar esquema de color | Tecla `+` |
| Ajustar parte real de Julia | `o` (disminuir) / `p` (aumentar) |
| Cerrar ventana | `ESC` o botón de cierre |

---

## Estructura del proyecto

```
fract-ol/
├── main.c              # Punto de entrada; análisis de argumentos e inicialización del fractal
├── mandelbrot.c        # Renderizado del conjunto de Mandelbrot
├── julia.c             # Renderizado del conjunto de Julia
├── minilibx-utils.c    # Utilidades de ventana, hooks y dibujo de píxeles
├── color-utils.c       # Cálculo central de colores
├── color-schemes.c     # Definiciones de paletas de color (clásica, cálida, fría…)
├── color-schemes2.c    # Definiciones de paletas adicionales (pastel, púrpura, cian)
├── init_fractal.c      # Helpers de inicialización del estado del fractal
├── fractol.h           # Cabecera compartida (structs, defines, prototipos)
├── Makefile
├── libft/              # Biblioteca de utilidades C personalizada
└── minilibx-linux/     # Biblioteca gráfica MiniLibX
```

---

## Autor

**ruortiz-** — estudiante de 42
