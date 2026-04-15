# Getting Started

Run `npm run dev` to test locally. This project uses SvelteKit for the frontend, and connects to a Django backend.

Static files such as the competiiton and workshop pdfs are stored under `competitions-data` and `workshops` in the static-data folder. Since they were moved from the old website,
I have just copied pasted this data across and tried to make the new website work with that is currently in those files (to save time
having to manually rewrite all the markdown files, routing, etc).

Its a static website so any pre-rendering is turned off. Currently, I host it on an S3 bucket, and it's on a Content Delivery Network (CDN) through Amazon CloudFront.
Really any cloud provider will suffice though.

When using in production, make sure to change the `.env` file to the actual
public api url though in production. It's set to `http://0.0.0.0:8000/` for now in the `.env.example` file, which is the port Django uses.

To deploy, I usually run these steps for an AWS based workflow, though steps are similar for any cloud provider will.
```
1. npm run build
2. npm run preview
3. aws s3 sync build/ s3://<NAME_OF_BUCKET> --delete
4. aws cloudfront create-invalidation --distribution-id <DISTRIBUTION_ID> --paths "/*"
```
For image assets, see `src > lib > assets`. The little graphics and gradient background effets are stored here. They were edited or made in Photoshop. The "grain" effect is done using the Camera Raw Filter and a grain size of 20-40.

Components are under `src > lib > components`

The main code is under `src > lib > routes`. There is a folder for each page. Styling is done using tailwind.css, though there is some manual global styles as well
under `layout.css` (especially for making the leaderboards for competitions work).

The navigation menu is provided by Bits-UI, see here: https://bits-ui.com/docs/components/navigation-menu

If you are adding an workshop or competition, just do the same as you usually would for the old website creating a new folder and adding
relevant files under `static-data > competitions-data` or `static-data > workshops`. Then go into `routes > competitions > competitions.md`
or `routes > workshops > workshops.md` and modify it with the relevant links. The website uses a markdown parser called
Marked (https://www.npmjs.com/package/marked) to render it on the website.

The only time API calls are made is under the Blogs page, to recieve the relevant information. It is then parsed by marked
and rendered onto the page. The relevant API calls to the backend are:
```
/api/blog_items/by_slug/${slug}/ - Gets the relevant information for ablog
/api/blog_items/get_next_by_slug/${slug}/ - For the "Read another article" section
/api/blog_items/shortened/ - For browsing all available blogs
/api/blog_items/filter_by_tags/ - If the user decides to filter. Its also shortened.
```

For an easter egg, there is a 404 error page with which has a nice graphic and displays some different error pages. On the
"Stay Updated" page, the `float Q_rsqrt(void) &#123; i  = 0x5f3759df - ( i >> 1 ); &#125;` text is inspired by https://en.wikipedia.org/wiki/Fast_inverse_square_root. Try to find a "COMPS" hidden in the binary somewhere on that same page :)

---

# sv

Everything you need to build a Svelte project, powered by [`sv`](https://github.com/sveltejs/cli).

## Creating a project

If you're seeing this, you've probably already done this step. Congrats!

```sh
# create a new project in the current directory
npx sv create

# create a new project in my-app
npx sv create my-app
```

## Developing

Once you've created a project and installed dependencies with `npm install` (or `pnpm install` or `yarn`), start a development server:

```sh
npm run dev

# or start the server and open the app in a new browser tab
npm run dev -- --open
```

## Building

To create a production version of your app:

```sh
npm run build
```

You can preview the production build with `npm run preview`.

> To deploy your app, you may need to install an [adapter](https://svelte.dev/docs/kit/adapters) for your target environment.
