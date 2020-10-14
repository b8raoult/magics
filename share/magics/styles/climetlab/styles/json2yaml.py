#!/usr/bin/env python
import json
import yaml
import sys


def tidy(x):
    if isinstance(x, list):
        return [tidy(y) for y in x]

    if isinstance(x, dict):
        d = {}
        for k, v in x.items():
            d[k] = tidy(v)

            if k in ("contour_level_list", "contour_shade_height_table"):
                d[k] = [float(y) for y in d[k].split("/")]

            if "_colour" in k and isinstance(d[k], str):
                d[k] = d[k].lower()

            if "_list" in k and isinstance(d[k], str):
                d[k] = tidy(d[k].split("/"))

            if "_list" in k and isinstance(d[k], str):
                d[k] = tidy(d[k].split("/"))

        return d

    if x == "on":
        return True

    if x == "off":
        return True

    if isinstance(x, str):
        return x.strip()

    return x


with open("../../ecmwf/styles.json") as f:
    styles = json.loads(f.read())

for k, v in styles.items():
    try:
        y = tidy(dict(magics=dict(mcont=v)))
        with open(k + ".yaml", "w") as f:

            print(yaml.safe_dump(y, default_flow_style=False), file=f)
    except Exception as e:
        print(k)
        print(e)
        print(v)
        # exit(1)
