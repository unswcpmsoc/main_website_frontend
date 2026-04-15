import adapter from '@sveltejs/adapter-static';
import { vitePreprocess } from '@sveltejs/vite-plugin-svelte';

/** @type {import('@sveltejs/kit').Config} */
const config = {
	// Consult https://svelte.dev/docs/kit/integrations
	// for more information about preprocessors
	preprocess: vitePreprocess(),

	kit: {
        files: {
            assets: 'static-data'
        },
		// adapter-auto only supports some environments, see https://svelte.dev/docs/kit/adapter-auto for a list.
		// If your environment is not supported, or you settled on a specific environment, switch out the adapter.
		// See https://svelte.dev/docs/kit/adapters for more information about adapters.
		adapter: adapter({
            pages: 'build',
            assets: 'build',
            fallback: 'index.html'
        }),
        prerender: {
            handleHttpError: ({ path, referrer, message }) => {
                if (referrer && referrer.includes('/competitions/')) {
                    return;
                }
                console.warn(message);
            }
        }
	},
    compilerOptions: {
        // Since we want to use Svelte 5 only
        runes: true
    }
};

export default config;
