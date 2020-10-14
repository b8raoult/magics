#!/usr/bin/env python
import json
import yaml
import re

FIX = {}


def number(x):

    if x in ("None", "none"):
        return None

    try:
        return int(x)
    except:
        return float(x)


def scale(x):
    if x > 1:
        return x / 255.0
    return x


def color(x):
    r = y = None
    try:
        x = [
            v.strip()
            for v in x.replace(" ", "").replace("(", ",").replace(")", "").split(",")
        ]
        r = x.pop(0)
        y = [number(v) for v in x]
        if x[0] == "rgb":
            y = [scale(v) for v in y]
        x = "%s(%s)" % (r, ",".join([str(v) for v in y]))

    except Exception:
        print(x, y, r)
        raise
    return x


def tidy(x):
    if isinstance(x, list):
        return [tidy(y) for y in x]

    if isinstance(x, dict):
        d = {}
        for k, v in x.items():
            k = FIX.get(k, k)
            # assert k.startswith("contour"), k
            d[k] = tidy(v)

            if k in (
                "contour_level_list",
                "contour_shade_height_table",
                "contour_line_thickness_rainbow_list",
                "contour_shade_marker_table",
                "symbol_advanced_table_level_list",
                "symbol_advanced_table_marker_list",
            ):
                d[k] = [number(y) for y in d[k].split("/")]

            if k in (
                "contour_shade_cell_resolution",
                "contour_shade_max_level",
                "contour_shade_min_level",
                "contour_max_level",
                "contour_min_level",
                "contour_interval",
                "contour_reference_level",
            ):
                d[k] = number(d[k])

            if "_colour" in k and isinstance(d[k], str):
                d[k] = d[k].lower()

            if "_list" in k and isinstance(d[k], str):
                d[k] = tidy(d[k].split("/"))

            if "_table" in k and isinstance(d[k], str):
                d[k] = tidy(d[k].split("/"))

        return d

    if x == "on":
        return True

    if x == "off":
        return False

    if isinstance(x, str):
        x = x.strip()
        assert x
        if "/" not in x and (
            x.startswith("rgb(")
            or x.startswith("rgba(")
            or x.startswith("hsl(")
            or x.startswith("hsv(")
        ):
            x = color(x)

    return x


with open("../../ecmwf/styles.json") as f:
    styles = json.loads(f.read())

for k, v in styles.items():
    try:
        v = tidy(v)
        y = dict(magics=dict(mcont=v))
        with open(k + ".yaml", "w") as f:

            print(yaml.safe_dump(y, default_flow_style=False), file=f)
    except Exception as e:
        print(k)
        print(e)
        print(v)
        exit(1)
